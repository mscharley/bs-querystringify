open Jest;
open QueryStringify;

describe("parse", () => {
  open Expect;

  test("with prefix", () =>
    expect(parseQueryString("?foo=bar"))
    |> toEqual([("foo", "bar")] |> Js.Dict.fromList)
  );
  test("without prefix", () =>
    expect(parseQueryString("foo=bar"))
    |> toEqual([("foo", "bar")] |> Js.Dict.fromList)
  );
  test("multiple args", () =>
    expect(parseQueryString("foo=bar&bar=foo"))
    |> toEqual([("foo", "bar"), ("bar", "foo")] |> Js.Dict.fromList)
  );
  test("with default", () =>
    expect(parseQueryString("foo&bar=foo"))
    |> toEqual([("foo", ""), ("bar", "foo")] |> Js.Dict.fromList)
  );
});

describe("stringify", () => {
  open Expect;

  test("without prefix", () =>
    expect(stringifyQuery([("foo", "bar")] |> Js.Dict.fromList))
    |> toEqual("foo=bar")
  );
  test("with prefix", () =>
    expect(
      stringifyQueryWithPrefix([("foo", "bar")] |> Js.Dict.fromList, true),
    )
    |> toEqual("?foo=bar")
  );
  test("with custom prefix", () =>
    expect(
      stringifyQueryWithPrefixString(
        [("foo", "bar")] |> Js.Dict.fromList,
        "&",
      ),
    )
    |> toEqual("&foo=bar")
  );
  test("with default", () =>
    expect(
      stringifyQueryWithPrefixString(
        [("foo", "")] |> Js.Dict.fromList,
        "&",
      ),
    )
    |> toEqual("&foo=")
  );
});

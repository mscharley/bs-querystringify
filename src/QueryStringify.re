[@bs.module "querystringify"] [@bs.val]
external parseQueryString: string => Js.Dict.t(string) = "parse";

[@bs.module "querystringify"] [@bs.val]
external stringifyQuery: Js.Dict.t(string) => string = "stringify";

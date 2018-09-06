module History = {
  type t;
};

[@bs.module "history"]
external createBrowserHistory:
  {
    .
    "basename": string,
    "forceRefresh": Js.boolean,
    "keyLength": int,
  } =>
  History.t =
  "";
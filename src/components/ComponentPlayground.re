[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "ComponentPlayground";

/* TODO it's abstract, figure it out */
type scope;

type componentPlaygroundTheme = [ | `light | `dark];

let make =
    (
      ~code: option(string)=?,
      ~previewBackgroundColor: option(string)=?,
      ~theme: option(componentPlaygroundTheme)=?,
      ~scope: option(scope)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "code": Js.Nullable.from_opt(code),
      "previewBackgroundColor": Js.Nullable.from_opt(previewBackgroundColor),
      "theme": Js.Nullable.from_opt(theme),
      "scope": Js.Nullable.from_opt(scope)
    },
    children
  );
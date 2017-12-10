[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "ComponentPlayground";

type scope;

type componentPlaygroundTheme =
  | Light
  | Dark;

let make =
    (
      ~code: option(string)=?,
      ~previewBackgroundColor: option(string)=?,
      ~theme: option(componentPlaygroundTheme)=?,
      /* TODO it's abstract, figure it out */
      ~scope: option(scope)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "code": from_opt(code),
          "previewBackgroundColor": from_opt(previewBackgroundColor),
          "theme": from_opt(theme),
          "scope": from_opt(scope)
        }
      ),
    children
  );
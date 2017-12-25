[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "ComponentPlayground";

type scope;

type componentPlaygroundTheme =
  | Light
  | Dark;

let componentPlaygroundThemeToJs = (theme) =>
  switch theme {
  | Light => "light"
  | Dark => "dark"
  };

let make =
    (
      ~code: option(string)=?,
      ~previewBackgroundColor: option(string)=?,
      ~theme: option(componentPlaygroundTheme)=?,
      ~scope: option(Js.t('a))=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "code": from_opt(code),
          "previewBackgroundColor": from_opt(previewBackgroundColor),
          "theme": Option.map(componentPlaygroundThemeToJs, theme) |> from_opt,
          "scope": from_opt(scope)
        }
      ),
    children
  );
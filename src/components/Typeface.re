[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Typeface";

let make =
    (
      ~font: option(string)=?,
      ~googleFont: option(string)=?,
      ~weight: option(int)=?,
      ~italic: option(bool)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "font": from_opt(font),
          "googleFont": from_opt(googleFont),
          "weight": from_opt(weight),
          "italic": Option.to_js_boolean(italic)
        }
      ),
    children
  );
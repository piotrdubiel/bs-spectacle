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
          "font": fromOption(font),
          "googleFont": fromOption(googleFont),
          "weight": fromOption(weight),
          "italic": Option.to_js_boolean(italic)
        }
      ),
    children
  );
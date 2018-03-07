[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "TableBody";

let make =
    (
      ~italic: option(bool)=?,
      ~bold: option(bool)=?,
      ~caps: option(bool)=?,
      ~margin: option(string)=?,
      ~padding: option(string)=?,
      ~textColor: option(string)=?,
      ~textSize: option(string)=?,
      ~textAlign: option(string)=?,
      ~textFont: option(string)=?,
      ~bgColor: option(string)=?,
      ~bgImage: option(string)=?,
      ~bgSize: option(string)=?,
      ~bgPosition: option(string)=?,
      ~bgRepeat: option(string)=?,
      ~bgDarken: option(float)=?,
      ~overflow: option(string)=?,
      ~height: option(string)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "italic": Option.to_js_boolean(italic),
          "bold": Option.to_js_boolean(bold),
          "caps": Option.to_js_boolean(caps),
          "margin": fromOption(margin),
          "padding": fromOption(padding),
          "textColor": fromOption(textColor),
          "textSize": fromOption(textSize),
          "textAlign": fromOption(textAlign),
          "textFont": fromOption(textFont),
          "bgColor": fromOption(bgColor),
          "bgImage": fromOption(bgImage),
          "bgSize": fromOption(bgSize),
          "bgPosition": fromOption(bgPosition),
          "bgRepeat": fromOption(bgRepeat),
          "bgDarken": fromOption(bgDarken),
          "overflow": fromOption(overflow),
          "height": fromOption(height)
        }
      ),
    children
  );
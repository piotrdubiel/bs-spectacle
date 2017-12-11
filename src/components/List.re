[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "List";

/* ordered	PropTypes.bool	Render as <ol>-tag
   reversed	PropTypes.bool	Set the reversed attribute
   start	PropTypes.bool	Set the start attribute, Default: 1
   type	PropTypes.bool	Set the type attribute. Default: "1" */
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
      /* List specific props */
      ~ordered: option(bool)=?,
      ~reversed: option(bool)=?,
      ~start: option(int)=?,
      ~type_: option(string)=?,
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
          "margin": from_opt(margin),
          "padding": from_opt(padding),
          "textColor": from_opt(textColor),
          "textSize": from_opt(textSize),
          "textAlign": from_opt(textAlign),
          "textFont": from_opt(textFont),
          "bgColor": from_opt(bgColor),
          "bgImage": from_opt(bgImage),
          "bgSize": from_opt(bgSize),
          "bgPosition": from_opt(bgPosition),
          "bgRepeat": from_opt(bgRepeat),
          "bgDarken": from_opt(bgDarken),
          "overflow": from_opt(overflow),
          "height": from_opt(height),
          /* List specific props */
          "ordered": Option.to_js_boolean(ordered),
          "reversed": Option.to_js_boolean(reversed),
          "start": from_opt(start),
          "type_": from_opt(type_)
        }
      ),
    children
  );
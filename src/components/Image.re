[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Image";

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
      /* Image specific props */
      ~src: string,
      ~alt: option(string)=?,
      ~display: option(string)=?,
      ~width: option(string)=?,
      ~height: option(string)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "italic": Js.Nullable.from_opt(italic),
      "bold": Js.Nullable.from_opt(bold),
      "caps": Js.Nullable.from_opt(caps),
      "margin": Js.Nullable.from_opt(margin),
      "padding": Js.Nullable.from_opt(padding),
      "textColor": Js.Nullable.from_opt(textColor),
      "textSize": Js.Nullable.from_opt(textSize),
      "textAlign": Js.Nullable.from_opt(textAlign),
      "textFont": Js.Nullable.from_opt(textFont),
      "bgColor": Js.Nullable.from_opt(bgColor),
      "bgImage": Js.Nullable.from_opt(bgImage),
      "bgSize": Js.Nullable.from_opt(bgSize),
      "bgPosition": Js.Nullable.from_opt(bgPosition),
      "bgRepeat": Js.Nullable.from_opt(bgRepeat),
      "bgDarken": Js.Nullable.from_opt(bgDarken),
      "overflow": Js.Nullable.from_opt(overflow),
      /* Image specific props */
      "src": src,
      "alt": Js.Nullable.from_opt(alt),
      "display": Js.Nullable.from_opt(display),
      "width": Js.Nullable.from_opt(width),
      "height": Js.Nullable.from_opt(height)
    },
    children
  );
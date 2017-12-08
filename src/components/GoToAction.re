[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "GoToAction";

type goToSlideAction = string => unit;

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
      /* GoToAction specific props */
      ~slide: option(int)=?,
      ~render: option((goToSlideAction => ReasonReact.reactElement))=?,
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
      "height": Js.Nullable.from_opt(height),
      /* GoToAction specific props */
      "slide": Js.Nullable.from_opt(slide),
      "render": Js.Nullable.from_opt(render)
    },
    children
  );
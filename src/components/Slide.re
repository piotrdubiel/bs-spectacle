open Types;

[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Slide";

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
      /* Slide specific props */
      ~align: option(string)=?,
      ~controlColor: option(string)=?,
      ~goTo: option(int)=?,
      ~id: option(string)=?,
      ~maxHeight: option(int)=?,
      ~maxWidth: option(int)=?,
      ~notes: option(string)=?,
      ~onActive: option((int => unit))=?,
      ~progressColor: option(string)=?,
      ~transition: array(transition)=[||],
      ~transitionIn: array(transition)=[||],
      ~transitionOut: array(transition)=[||],
      ~transitionDuration: option(int)=?,
      ~getAppearStep: option((int => unit))=?,
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
      /* Slide specific props */
      "align": Js.Nullable.from_opt(align),
      "controlColor": Js.Nullable.from_opt(controlColor),
      "goTo": Js.Nullable.from_opt(goTo),
      "id": Js.Nullable.from_opt(id),
      "maxHeight": Js.Nullable.from_opt(maxHeight),
      "maxWidth": Js.Nullable.from_opt(maxWidth),
      "notes": Js.Nullable.from_opt(notes),
      "onActive": Js.Nullable.from_opt(onActive),
      "progressColor": Js.Nullable.from_opt(progressColor),
      "transition": transition,
      "transitionIn": transitionIn,
      "transitionOut": transitionOut,
      "transitionDuration": Js.Nullable.from_opt(transitionDuration),
      "getAppearStep": Js.Nullable.from_opt(getAppearStep)
    },
    children
  );
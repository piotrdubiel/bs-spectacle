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
      /* TODO support transition function */
      ~transition: array(transition)=[||],
      /* TODO support transition function */
      ~transitionIn: array(transition)=[||],
      /* TODO support transition function */
      ~transitionOut: array(transition)=[||],
      ~transitionDuration: option(int)=?,
      ~getAppearStep: option((int => unit))=?,
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
          /* Slide specific props */
          "align": from_opt(align),
          "controlColor": from_opt(controlColor),
          "goTo": from_opt(goTo),
          "id": from_opt(id),
          "maxHeight": from_opt(maxHeight),
          "maxWidth": from_opt(maxWidth),
          "notes": from_opt(notes),
          "onActive": from_opt(onActive),
          "progressColor": from_opt(progressColor),
          "transition": Array.map(transitionToJs, transition),
          "transitionIn": Array.map(transitionToJs, transitionIn),
          "transitionOut": Array.map(transitionToJs, transitionOut),
          "transitionDuration": from_opt(transitionDuration),
          "getAppearStep": from_opt(getAppearStep)
        }
      ),
    children
  );
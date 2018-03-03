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
          "height": fromOption(height),
          /* Slide specific props */
          "align": fromOption(align),
          "controlColor": fromOption(controlColor),
          "goTo": fromOption(goTo),
          "id": fromOption(id),
          "maxHeight": fromOption(maxHeight),
          "maxWidth": fromOption(maxWidth),
          "notes": fromOption(notes),
          "onActive": fromOption(onActive),
          "progressColor": fromOption(progressColor),
          "transition": Array.map(transitionToJs, transition),
          "transitionIn": Array.map(transitionToJs, transitionIn),
          "transitionOut": Array.map(transitionToJs, transitionOut),
          "transitionDuration": fromOption(transitionDuration),
          "getAppearStep": fromOption(getAppearStep)
        }
      ),
    children
  );
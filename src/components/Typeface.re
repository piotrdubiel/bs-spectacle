[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Typeface";

[@bs.obj]
external makeProps :
  (~font: string=?, ~googleFont: string=?, ~weight: int=?, ~italic: Js.boolean=?, unit) => _ =
  "";

let make = (~font=?, ~googleFont=?, ~weight=?, ~italic=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~font?, ~googleFont?, ~weight?, ~italic=?Types.to_js_boolean(italic), ()),
    children
  );
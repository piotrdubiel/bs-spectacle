[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Fill";

let make = (children) => ReasonReact.wrapJsForReason(~reactClass, children);
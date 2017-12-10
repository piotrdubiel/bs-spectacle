[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Fit";

let make = (children) => ReasonReact.wrapJsForReason(~reactClass, children);
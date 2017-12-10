[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Appear";

let make = (~order: option(int)=?, ~fid: option(string)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=Js.Nullable.({"order": from_opt(order), "fid": from_opt(fid)}),
    children
  );
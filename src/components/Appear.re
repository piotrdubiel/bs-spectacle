[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Appear";

let make = (~order: option(int)=?, ~fid: option(string)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={"order": Js.Nullable.from_opt(order), "fid": Js.Nullable.from_opt(fid)},
    children
  );
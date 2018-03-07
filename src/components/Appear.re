[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Appear";

let make = (~order: option(int)=?, ~fid: option(string)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=Js.Nullable.({"order": fromOption(order), "fid": fromOption(fid)}),
    children
  );
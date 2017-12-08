type history;

[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Spectacle";

let make = (~history: history, ~theme: Theme.theme, children) =>
  ReasonReact.wrapJsForReason(~reactClass, ~props={"theme": theme, "history": history}, children);

module List = {
  [@bs.module "spectacle"] external listReactClass : ReasonReact.reactClass = "List";
  let make =
      (~ordered: bool=false, ~reversed: bool=false, ~start: int=1, ~type_: string="1", children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=listReactClass,
      ~props={
        "ordered": Js.Boolean.to_js_boolean(ordered),
        "reversed": Js.Boolean.to_js_boolean(reversed),
        "start": start,
        "type": type_
      },
      children
    );
};

module ListItem = {
  [@bs.module "spectacle"] external listItemReactClass : ReasonReact.reactClass = "ListItem";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=listItemReactClass, ~props=Js.Obj.empty(), children);
};

module Notes = {
  [@bs.module "spectacle"] external notesReactClass : ReasonReact.reactClass = "Notes";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=notesReactClass, ~props=Js.Obj.empty(), children);
};

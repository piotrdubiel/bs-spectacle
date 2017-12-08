open Types;

[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Deck";

let make =
    (
      ~controls: option(bool)=?,
      ~contentHeight: option(int)=?,
      ~contentWidth: option(int)=?,
      ~history: option(history)=?,
      ~progress: progress=`pacman,
      ~theme: option(Theme.theme)=?,
      ~transition: array(transition)=[||],
      ~transitionDuration: option(int)=?,
      ~autoplay: option(bool)=?,
      ~autoplayDuration: option(int)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "controls": Js.Nullable.from_opt(controls),
      "contentHeight": Js.Nullable.from_opt(contentHeight),
      "contentWidth": Js.Nullable.from_opt(contentWidth),
      "history": Js.Nullable.from_opt(history),
      "progress": progressToJs(progress),
      "theme": Js.Nullable.from_opt(theme),
      "transition": Array.map(transitionToJs, transition),
      "transitionDuration": Js.Nullable.from_opt(transitionDuration),
      "autoplay": Js.Nullable.from_opt(autoplay),
      "autoplayDuration": Js.Nullable.from_opt(autoplayDuration)
    },
    children
  );
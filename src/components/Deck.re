open Types;

[@bs.module "spectacle"] external reactClass : ReasonReact.reactClass = "Deck";

let make =
    (
      ~controls: option(bool)=?,
      ~contentHeight: option(int)=?,
      ~contentWidth: option(int)=?,
      /* TODO implement history, right now it's abstract*/
      ~history: option('a)=?,
      ~progress: option(progress)=?,
      ~theme: option(Theme.theme)=?,
      ~transition: array(transition)=[||],
      ~transitionDuration: option(int)=?,
      ~autoplay: option(bool)=?,
      ~autoplayDuration: option(int)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "controls": Option.to_js_boolean(controls),
          "contentHeight": from_opt(contentHeight),
          "contentWidth": from_opt(contentWidth),
          "history": from_opt(history),
          "progress": Option.map(progressToJs, progress),
          "theme": from_opt(theme),
          "transition": Array.map(transitionToJs, transition),
          "transitionDuration": from_opt(transitionDuration),
          "autoplay": Option.to_js_boolean(autoplay),
          "autoplayDuration": from_opt(autoplayDuration)
        }
      ),
    children
  );
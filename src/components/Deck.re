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
          "contentHeight": fromOption(contentHeight),
          "contentWidth": fromOption(contentWidth),
          "history": fromOption(history),
          "progress": Option.map(progressToJs, progress),
          "theme": fromOption(theme),
          "transition": Array.map(transitionToJs, transition),
          "transitionDuration": fromOption(transitionDuration),
          "autoplay": Option.to_js_boolean(autoplay),
          "autoplayDuration": fromOption(autoplayDuration)
        }
      ),
    children
  );
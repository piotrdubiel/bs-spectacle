[@bs.deriving jsConverter]
type progress = [ | `pacman | `bar | `number | `none];

type functionTransition = (~transitioning: bool, ~forward: bool, unit) => ReactDOMRe.Style.t;

type transition =
  | Slide
  | Zoom
  | Fade
  | Spin
  | Custom(functionTransition);

let transitionToJs = (transition) =>
  switch transition {
  | Slide => Obj.magic("slide")
  | Zoom => Obj.magic("zoom")
  | Fade => Obj.magic("fade")
  | Spin => Obj.magic("spin")
  | Custom(f) =>
    Obj.magic(
      (transitioning, forward) =>
        f(~transitioning=Js.to_bool(transitioning), ~forward=Js.to_bool(forward), ())
    )
  };
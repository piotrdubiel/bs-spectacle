[@bs.deriving jsConverter]
type progress = [ | `pacman | `bar | `number | `none];

[@bs.deriving jsConverter]
type transition = [ | `slide | `zoom | `fade | `spin];

type history;
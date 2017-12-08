let map = (f, x) =>
  switch x {
  | None => None
  | Some(x) => Some(f(x))
  };
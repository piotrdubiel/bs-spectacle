let map = (f, x) =>
  switch x {
  | None => None
  | Some(x) => Some(f(x))
  };

let to_js_boolean = (a) => a |> map(Js.Boolean.to_js_boolean) |> Js.Nullable.fromOption;
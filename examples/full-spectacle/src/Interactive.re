open BsSpectacle;

let s = ReasonReact.string;

type action =
  | Increment;

type state = int;

let component = ReasonReact.reducerComponent("Interactive");

let make = _children => {
  ...component,
  initialState: () => 0,
  reducer: (action, state) =>
    switch (action) {
    | Increment => ReasonReact.Update(state + 1)
    },
  render: ({state, reduce}) =>
    <div>
      {
        state < 5 ?
          <div>
            <Heading size=5 textColor="black">
              {s({j|The button has been clicked $state times|j})}
            </Heading>
            <button
              _type="button"
              style={
                ReactDOMRe.Style.make(
                  ~padding="20px",
                  ~background="black",
                  ~minWidth="300px",
                  ~marginTop="20px",
                  ~fontFamily="inherit",
                  ~textTransform="uppercase",
                  ~border="none",
                  ~color="white",
                  ~outline="none",
                  ~fontWeight="bold",
                  ~fontSize="2em",
                  (),
                )
              }
              onClick={reduce(_ => Increment)}>
              {s("Click Me")}
            </button>
          </div> :
          <Heading size=5 fit=true caps=true textColor="black">
            {s("Easy there pal")}
          </Heading>
      }
    </div>,
};

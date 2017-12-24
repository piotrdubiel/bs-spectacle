open BsSpectacle;

let theme =
  Theme.(
    createTheme(
      {primary: "#26A0D1", secondary: "white", tertiary: "#505050", quarternary: "white"},
      {
        primary: {name: "Merriweather", googleFont: true, styles: [|"300"|]},
        secondary: {name: "Roboto", googleFont: true, styles: [|"100"|]},
        tertiary: simpleFont("monospace")
      }
    )
  );

let s = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Simple");

let customTransition = (~transitioning, ~forward, ()) => {
  let angle = forward ? (-180) : 180;
  let translateY = transitioning ? 100 : 0;
  let rotation = transitioning ? angle : 0;
  let transform = {j|
    translate3d(0%, $(translateY)%, 0)
    rotate($(rotation)deg)
    |j};
  let backgroundColor = transitioning ? "#000" : "#26A0D1";
  ReactDOMRe.Style.make(~transform, ~backgroundColor, ())
};

let make = (_children) => {
  ...component,
  render: (_self) =>
    <Deck transition=[|Zoom, Slide, Custom(customTransition)|] theme>
      <Slide>
        <Heading textColor="secondary" textFont="secondary"> (s("Hello, world")) </Heading>
      </Slide>
      <Slide transition=[|Slide|] bgColor="secondary">
        <BlockQuote>
          <Quote> (s({js|It’s easy, see...|js})) </Quote>
          <Cite> (s("Unknown")) </Cite>
        </BlockQuote>
      </Slide>
    </Deck>
};
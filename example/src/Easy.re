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

let component = ReasonReact.statelessComponent("Easy");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <Deck transition=[|`zoom, `slide|] theme>
      <Slide>
        <Heading textColor="secondary" textFont="secondary"> (s("Hello, world")) </Heading>
      </Slide>
      <Slide transition=[|`slide|] bgColor="secondary">
        <BlockQuote>
          <Quote> (s({js|It’s easy, see...|js})) </Quote>
          <Cite> (s("Unknown")) </Cite>
        </BlockQuote>
      </Slide>
    </Deck>
};
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

let component = ReasonReact.statelessComponent("Extras");

let customTransition = (~transitioning, ~forward, ()) => {
  let angle = forward ? (-180) : 180;
  let translateY = transitioning ? 100 : 0;
  let rotation = transitioning ? angle : 0;
  let transform = {j|
    translate3d(0%, $(translateY)%, 0)
    rotate($(rotation)deg)
    |j};
  let backgroundColor = transitioning ? "#fff" : "#26A0D1";
  ReactDOMRe.Style.make(~transform, ~backgroundColor, ())
};

let make = (_children) => {
  ...component,
  render: (_self) =>
    <Deck transition=[|Zoom, Slide|] theme>
      <Slide transition=[|Custom(customTransition)|]>
        <Notes>
          <h1> (s("Introduction")) </h1>
          <ol> <li> (s("Clap your hands")) </li> <li> (s("Say yeah")) </li> </ol>
        </Notes>
        <Heading textColor="secondary" textFont="secondary"> (s("Hello, world")) </Heading>
      </Slide>
      <Slide transition=[|Slide|] bgColor="secondary" notes="It will be overwritten">
        <Notes> (s("Overwriting notes from props")) </Notes>
        <BlockQuote>
          <Quote> (s({js|It’s easy, see...|js})) </Quote>
          <Cite> (s("Unknown")) </Cite>
        </BlockQuote>
      </Slide>
      <Slide bgColor="secondary">
        <ComponentPlayground
          previewBackgroundColor="#26A0D1"
          code={js|
log("This log is provided thanks to SCOPE!")

const styles = {
  heading: {
    fontSize: "2.25rem",
    fontWeight: "bold"
  }
}

const HelloWorld = ({ name }) => (
  <div>
    <h1 style={styles.heading}>
      Create Live Code Examples in {name}!
    </h1>
  </div>
)

render(<HelloWorld name="Spectacle" />)
         |js}
          theme=Light
          scope={"log": (msg: string) => Js.log2("FROM REASON:", msg)}
        />
      </Slide>
      <Magic>
        <Slide bgColor="secondary">
          <Heading size=3> (s({js|It’s a kind of magic...|js})) </Heading>
        </Slide>
        <Slide bgColor="secondary">
          <Heading size=3> (s("<Magic>")) </Heading>
          <Heading size=3> (s("</Magic>")) </Heading>
        </Slide>
      </Magic>
    </Deck>
};
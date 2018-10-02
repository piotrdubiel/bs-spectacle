open BsSpectacle;

let theme =
  Theme.(
    createTheme(
      {
        primary: "#ff4081",
        secondary: "black",
        tertiary: "white",
        quarternary: "white",
      },
      {
        primary: {
          name: "Open Sans Condensed",
          googleFont: true,
          styles: [|"300", "700"|],
        },
        secondary: {
          name: "Lobster Two",
          googleFont: true,
          styles: [|"400", "700"|],
        },
        tertiary: simpleFont("monospace"),
      },
    )
  );

type images = {
  city: string,
  kat: string,
  logo: string,
  markdown: string,
};

let images: images = {
  city: [%raw {| require('./assets/city.jpg')|}],
  kat: [%raw {| require('./assets/kat.png')|}],
  logo: [%raw {| require('./assets/formidable-logo.svg')|}],
  markdown: [%raw {| require('./assets/markdown.png')|}],
};

Preloader.load(images);

let s = ReasonReact.string;

type state = {steps: int};

type action =
  | UpdateSteps(int)
  | NoUpdate;

let component = ReasonReact.reducerComponent("Presentation");

let make = _children => {
  ...component,
  initialState: () => {steps: 0},
  reducer: (action, _state) =>
    switch (action) {
    | UpdateSteps(steps) => ReasonReact.Update({steps: steps})
    | NoUpdate => ReasonReact.NoUpdate
    },
  render: ({state, reduce}) => {
    let markdownLogo = images.markdown;
    <Deck transition=[|Zoom, Slide|] theme transitionDuration=500>
      <Slide transition=[|Zoom|] bgColor="primary">
        <Heading size=1 fit=true caps=true lineHeight=1.0 textColor="black">
          "Spectacle"
        </Heading>
        <Heading size=1 fit=true caps=true>
          "A ReactJS Presentation Library"
        </Heading>
        <Heading size=1 fit=true caps=true textColor="black">
          "Where You Can Write Your Decks In JSX"
        </Heading>
        <Link href="https://github.com/FormidableLabs/spectacle">
          <Text bold=true caps=true textColor="tertiary">
            "View on Github"
          </Text>
        </Link>
        <Text textSize="1.5em" margin="20px 0px 0px" bold=true>
          "Hit Your Right Arrow To Begin!"
        </Text>
      </Slide>
      <Slide
        onActive={
          slideIndex => Js.log({j|Viewing slide index: $slideIndex|j})
        }
        id="wait-what"
        goTo=4
        transition=[|Fade|]
        bgColor="black"
        notes="You can even put notes on your slide. How awesome is that?">
        <Image src={images.kat} margin="0px auto 40px" />
        <Heading
          size=2 caps=true fit=true textColor="primary" textFont="primary">
          "Wait what?"
        </Heading>
      </Slide>
      <Slide
        transitionIn=[|Zoom, Fade|]
        transitionOut=[|Slide, Fade|]
        bgColor="primary"
        notes="<ul><li>talk about that</li><li>and that</li></ul>">
        <CodePane
          lang="jsx"
          source=Examples.deck
          margin="20px auto"
          overflow="overflow"
        />
      </Slide>
      <Slide goTo=3> <ComponentPlayground theme=Dark /> </Slide>
      <Slide transition=[|Slide|] bgImage={images.city} bgDarken=0.75>
        <Appear fid="1">
          <Heading size=1 caps=true fit=true textColor="primary">
            {s("Full Width")}
          </Heading>
        </Appear>
        <Appear fid="2">
          <Heading size=1 caps=true fit=true textColor="tertiary">
            "Adjustable Darkness"
          </Heading>
        </Appear>
        <Appear fid="3">
          <Heading size=1 caps=true fit=true textColor="primary">
            "Background Imagery"
          </Heading>
        </Appear>
      </Slide>
      <Slide>
        <Heading size=2 textColor="secondary" margin="0.25em">
          "Mix it up!"
        </Heading>
        <Heading size=6 textColor="tertiary">
          "You can even jump to different slides with a standard button or custom component!"
        </Heading>
        <GoToAction margin="1em" slide=8> "Jump to Slide 8" </GoToAction>
        <GoToAction
          render={
            goToSlide =>
              <select
                defaultValue=""
                style={
                  ReactDOMRe.Style.make(
                    ~background="#000",
                    ~color="#fff",
                    ~fontSize="1.1em",
                    ~fontFamily="Open Sans Condensed",
                    (),
                  )
                }
                onChange={
                  event =>
                    (
                      event
                      |> ReactEventRe.Form.target
                      |> ReactDOMRe.domElementToObj
                    )##value
                    |> goToSlide
                }>
                <option value="" disabled=Js.true_>
                  {s("Custom Slide Picker")}
                </option>
                <option value="wait-what"> {s("Wait What!? Slide")} </option>
                <option value="3"> {s("Slide 3")} </option>
              </select>
          }
        />
      </Slide>
      <Slide
        transition=[|Slide|]
        bgDarken=0.75
        getAppearStep={
          reduce(steps =>
            state.steps != steps ? UpdateSteps(steps) : NoUpdate
          )
        }>
        <Appear>
          <Heading size=1 caps=true textColor="tertiary"> "Can" </Heading>
        </Appear>
        <Appear>
          <Heading size=1 caps=true textColor="secondary"> "Count" </Heading>
        </Appear>
        <Appear>
          <Heading size=1 caps=true textColor="tertiary"> "Steps" </Heading>
        </Appear>
        <Heading size=1 caps=true fit=true textColor="secondary">
          {j|Steps: $state|j}
        </Heading>
      </Slide>
      <Slide transition=[|Zoom, Fade|] bgColor="primary">
        <Heading caps=true fit=true> "Flexible Layouts" </Heading>
        <Layout>
          <Fill>
            <Heading
              size=4
              caps=true
              textColor="secondary"
              bgColor="white"
              margin="10">
              "Left"
            </Heading>
          </Fill>
          <Fill>
            <Heading
              size=4
              caps=true
              textColor="secondary"
              bgColor="white"
              margin="10">
              "Right"
            </Heading>
          </Fill>
        </Layout>
      </Slide>
      <Slide transition=[|Slide|] bgColor="black">
        <BlockQuote>
          <Quote> {s("Wonderfully formatted quotes")} </Quote>
          <Cite> {s("Ken Wheeler")} </Cite>
        </BlockQuote>
      </Slide>
      <Slide
        transition=[|Spin, Zoom|]
        bgColor="tertiary"
        controlColor="primary"
        progressColor="primary">
        <Heading caps=true fit=true size=1 textColor="primary">
          {s("Inline Markdown")}
        </Heading>
        <Markdown
          source={j|
![Markdown Logo]($markdownLogo)
You can write inline images, [Markdown Links](http://commonmark.org), paragraph text and most other markdown syntax
* Lists too!
* With ~~strikethrough~~ and _italic_
* And let's not forget **bold**|j}
        />
      </Slide>
      {
        MarkdownSlides.make(
          {j|
#### Create Multiple Slides in Markdown
All the same tags and elements supported in <Markdown /> are supported in MarkdownSlides.
---
Slides are separated with **three dashes** and can be used _anywhere_ in the deck. The markdown can either be:
* A Tagged Template Literal
* Imported Markdown from another file
        |j},
        )
      }
      <Slide transition=[|Slide, Spin|] bgColor="primary">
        <Heading caps=true fit=true size=1 textColor="tertiary">
          {s("Smooth")}
        </Heading>
        <Heading caps=true fit=true size=1 textColor="secondary">
          {s("Combinable Transitions")}
        </Heading>
      </Slide>
      <SlideSet>
        <Slide transition=[|Fade|] bgColor="secondary" textColor="primary">
          <List>
            <Appear>
              <ListItem> {s("Inline style based theme system")} </ListItem>
            </Appear>
            <Appear> <ListItem> {s("Autofit text")} </ListItem> </Appear>
            <Appear>
              <ListItem> {s("Flexbox layout system")} </ListItem>
            </Appear>
            <Appear> <ListItem> {s("PDF export")} </ListItem> </Appear>
            <Appear> <ListItem> {s("And...")} </ListItem> </Appear>
          </List>
        </Slide>
        <Slide transition=[|Slide|] bgColor="primary">
          <Heading size=1 caps=true fit=true textColor="tertiary">
            {s("Your presentations are interactive")}
          </Heading>
          <Interactive />
        </Slide>
      </SlideSet>
      <Slide
        transition=[|Slide|]
        bgColor="primary"
        notes="Hard to find cities without any pizza">
        <Heading
          size=4 caps=true textColor="secondary" bgColor="white" margin="10px">
          {s("Pizza Toppings")}
        </Heading>
        <Layout>
          <Table>
            <TableHeader>
              <TableRow>
                <TableHeaderItem />
                <TableHeaderItem> {s("2011")} </TableHeaderItem>
                <TableHeaderItem> {s("2013")} </TableHeaderItem>
                <TableHeaderItem> {s("2015")} </TableHeaderItem>
              </TableRow>
            </TableHeader>
            <TableBody>
              <TableRow>
                <TableItem> {s("None")} </TableItem>
                <TableItem> {s("61.8%")} </TableItem>
                <TableItem> {s("39.6%")} </TableItem>
                <TableItem> {s("35.0%")} </TableItem>
              </TableRow>
              <TableRow>
                <TableItem> {s("Pineapple")} </TableItem>
                <TableItem> {s("28.3%")} </TableItem>
                <TableItem> {s("54.5%")} </TableItem>
                <TableItem> {s("61.5%")} </TableItem>
              </TableRow>
              <TableRow>
                <TableItem> {s("Pepperoni")} </TableItem>
                <TableItem />
                <TableItem> {s("50.2%")} </TableItem>
                <TableItem> {s("77.2%")} </TableItem>
              </TableRow>
              <TableRow>
                <TableItem> {s("Olives")} </TableItem>
                <TableItem />
                <TableItem> {s("24.9%")} </TableItem>
                <TableItem> {s("55.9%")} </TableItem>
              </TableRow>
            </TableBody>
          </Table>
        </Layout>
      </Slide>
      <Slide transition=[|Spin, Slide|] bgColor="tertiary">
        <Heading size=1 caps=true fit=true lineHeight=1.5 textColor="primary">
          {s("Made with love in Seattle by")}
        </Heading>
        <Link href="http://www.formidable.com">
          <Image width="100%" src={images.logo} />
        </Link>
      </Slide>
    </Deck>;
  },
};

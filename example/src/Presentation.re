open BsSpectacle;

let theme =
  Theme.(
    createTheme(
      {primary: "#ff4081", secondary: "black", tertiary: "white", quarternary: "white"},
      {
        primary: {name: "Open Sans Condensed", googleFont: true, styles: [|"300", "700"|]},
        secondary: {name: "Lobster Two", googleFont: true, styles: [|"400", "700"|]},
        tertiary: simpleFont("monospace")
      }
    )
  );

type images = {
  city: string,
  kat: string,
  logo: string,
  markdown: string
};

let images: images = {
  city: [%raw {| require('./assets/city.jpg')|}],
  kat: [%raw {| require('./assets/kat.png')|}],
  logo: [%raw {| require('./assets/formidable-logo.svg')|}],
  markdown: [%raw {| require('./assets/markdown.png')|}]
};

let s = ReasonReact.stringToElement;

type state = {steps: int};

type action =
  | UpdateSteps(int)
  | NoUpdate;

let component = ReasonReact.reducerComponent("Presentation");

let make = (_children) => {
  ...component,
  initialState: () => {steps: 0},
  reducer: (action, _state) =>
    switch action {
    | UpdateSteps(steps) => ReasonReact.Update({steps: steps})
    | NoUpdate => ReasonReact.NoUpdate
    },
  render: ({state, reduce}) => {
    let markdownLogo = images.markdown;
    <Deck transition=[|`zoom, `slide|] theme transitionDuration=500>
      <Slide transition=[|`zoom|] bgColor="primary">
        <Heading size=1 fit=true caps=true lineHeight=1.0 textColor="black"> "Spectacle" </Heading>
        <Heading size=1 fit=true caps=true> "A ReactJS Presentation Library" </Heading>
        <Heading size=1 fit=true caps=true textColor="black">
          "Where You Can Write Your Decks In JSX"
        </Heading>
        <Link href="https://github.com/FormidableLabs/spectacle">
          <Text bold=true caps=true textColor="tertiary"> "View on Github" </Text>
        </Link>
        <Text textSize="1.5em" margin="20px 0px 0px" bold=true>
          "Hit Your Right Arrow To Begin!"
        </Text>
      </Slide>
      <Slide
        onActive=((slideIndex) => Js.log({j|Viewing slide index: $slideIndex|j}))
        id="wait-what"
        goTo=4
        transition=[|
          `fade
          /* (transitioning, forward) => {
               const angle = forward ? -180 : 180;
               return {
                 transform: `
                   translate3d(0%, ${transitioning ? 100 : 0}%, 0)
                   rotate(${transitioning ? angle : 0}deg)
                 `,
                 backgroundColor: transitioning ? '#26afff' : '#000'
               };
             } */
        |]
        bgColor="black"
        notes="You can even put notes on your slide. How awesome is that?">
        <Image src=images.kat margin="0px auto 40px" />
        <Heading size=2 caps=true fit=true textColor="primary" textFont="primary">
          "Wait what?"
        </Heading>
      </Slide>
      <Slide
        transitionIn=[|`zoom, `fade|]
        transitionOut=[|`slide, `fade|]
        bgColor="primary"
        notes="<ul><li>talk about that</li><li>and that</li></ul>">
        <CodePane lang="jsx" source=Examples.deck margin="20px auto" overflow="overflow" />
      </Slide>
      <Slide goTo=3> <ComponentPlayground theme=`dark /> </Slide>
      <Slide transition=[|`slide|] bgImage=images.city bgDarken=0.75>
        <Appear fid="1">
          <Heading size=1 caps=true fit=true textColor="primary"> (s("Full Width")) </Heading>
        </Appear>
        <Appear fid="2">
          <Heading size=1 caps=true fit=true textColor="tertiary"> "Adjustable Darkness" </Heading>
        </Appear>
        <Appear fid="3">
          <Heading size=1 caps=true fit=true textColor="primary"> "Background Imagery" </Heading>
        </Appear>
      </Slide>
      <Slide>
        <Heading size=2 textColor="secondary" margin="0.25em"> "Mix it up!" </Heading>
        <Heading size=6 textColor="tertiary">
          "You can even jump to different slides with a standard button or custom component!"
        </Heading>
        <GoToAction margin="1em" slide=8> "Jump to Slide 8" </GoToAction>
        <GoToAction
          render=(
            (goToSlide) =>
              <select
                defaultValue=""
                style=(
                  ReactDOMRe.Style.make(
                    ~background="#000",
                    ~color="#fff",
                    ~fontSize="1.1em",
                    ~fontFamily="Open Sans Condensed",
                    ()
                  )
                )
                onChange=(
                  (event) =>
                    (event |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj)##value
                    |> goToSlide
                )>
                <option value="" disabled=Js.true_> (s("Custom Slide Picker")) </option>
                <option value="wait-what"> (s("Wait What!? Slide")) </option>
                <option value="3"> (s("Slide 3")) </option>
              </select>
          )
        />
      </Slide>
      <Slide
        transition=[|`slide|]
        bgDarken=0.75
        getAppearStep=(reduce((steps) => state.steps != steps ? UpdateSteps(steps) : NoUpdate))>
        <Appear> <Heading size=1 caps=true textColor="tertiary"> "Can" </Heading> </Appear>
        <Appear> <Heading size=1 caps=true textColor="secondary"> "Count" </Heading> </Appear>
        <Appear> <Heading size=1 caps=true textColor="tertiary"> "Steps" </Heading> </Appear>
        <Heading size=1 caps=true fit=true textColor="secondary"> {j|Steps: $state|j} </Heading>
      </Slide>
      <Slide transition=[|`zoom, `fade|] bgColor="primary">
        <Heading caps=true fit=true> "Flexible Layouts" </Heading>
        <Layout>
          <Fill>
            <Heading size=4 caps=true textColor="secondary" bgColor="white" margin="10">
              "Left"
            </Heading>
          </Fill>
          <Fill>
            <Heading size=4 caps=true textColor="secondary" bgColor="white" margin="10">
              "Right"
            </Heading>
          </Fill>
        </Layout>
      </Slide>
      <Slide transition=[|`slide|] bgColor="black">
        <BlockQuote>
          <Quote> (s("Wonderfully formatted quotes")) </Quote>
          <Cite> (s("Ken Wheeler")) </Cite>
        </BlockQuote>
      </Slide>
      <Slide
        transition=[|`spin, `zoom|]
        bgColor="tertiary"
        controlColor="primary"
        progressColor="primary">
        <Heading caps=true fit=true size=1 textColor="primary"> (s("Inline Markdown")) </Heading>
        <Markdown
          source={j|
![Markdown Logo]($markdownLogo)
You can write inline images, [Markdown Links](http://commonmark.org), paragraph text and most other markdown syntax
* Lists too!
* With ~~strikethrough~~ and _italic_
* And let's not forget **bold**|j}
        />
      </Slide>
    </Deck>
  }
};
/*


 <Slide transition={['spin', 'zoom']} bgColor="tertiary" controlColor="primary" progressColor="primary">
   <Heading caps fit size={1} textColor="primary">
     Inline Markdown
   </Heading>
   <Markdown>
     {`
 ![Markdown Logo](${images.markdown.replace('/', '')})
 You can write inline images, [Markdown Links](http://commonmark.org), paragraph text and most other markdown syntax
 * Lists too!
 * With ~~strikethrough~~ and _italic_
 * And let's not forget **bold**
     `}
   </Markdown>
 </Slide>
 {
   MarkdownSlides`
 #### Create Multiple Slides in Markdown
 All the same tags and elements supported in <Markdown /> are supported in MarkdownSlides.
 ---
 Slides are separated with **three dashes** and can be used _anywhere_ in the deck. The markdown can either be:
 * A Tagged Template Literal
 * Imported Markdown from another file
   `
 }
 <Slide transition={['slide', 'spin']} bgColor="primary">
   <Heading caps fit size={1} textColor="tertiary">
     Smooth
   </Heading>
   <Heading caps fit size={1} textColor="secondary">
     Combinable Transitions
   </Heading>
 </Slide>
 <SlideSet>
   <Slide transition={['fade']} bgColor="secondary" textColor="primary">
     <List>
       <Appear><ListItem>Inline style based theme system</ListItem></Appear>
       <Appear><ListItem>Autofit text</ListItem></Appear>
       <Appear><ListItem>Flexbox layout system</ListItem></Appear>
       <Appear><ListItem>PDF export</ListItem></Appear>
       <Appear><ListItem>And...</ListItem></Appear>
     </List>
   </Slide>
   <Slide transition={['slide']} bgColor="primary">
     <Heading size={1} caps fit textColor="tertiary">
       Your presentations are interactive
     </Heading>
     <Interactive/>
   </Slide>
 </SlideSet>
 <Slide transition={['slide']} bgColor="primary"
   notes="Hard to find cities without any pizza"
 >
   <Heading size={4} caps textColor="secondary" bgColor="white" margin={10}>
     Pizza Toppings
   </Heading>
   <Layout>
     <Table>
       <TableHeader>
         <TableRow>
           <TableHeaderItem/>
           <TableHeaderItem>2011</TableHeaderItem>
           <TableHeaderItem>2013</TableHeaderItem>
           <TableHeaderItem>2015</TableHeaderItem>
         </TableRow>
       </TableHeader>
       <TableBody>
         <TableRow>
           <TableItem>None</TableItem>
           <TableItem>61.8%</TableItem>
           <TableItem>39.6%</TableItem>
           <TableItem>35.0%</TableItem>
         </TableRow>
         <TableRow>
           <TableItem>Pineapple</TableItem>
           <TableItem>28.3%</TableItem>
           <TableItem>54.5%</TableItem>
           <TableItem>61.5%</TableItem>
         </TableRow>
         <TableRow>
           <TableItem>Pepperoni</TableItem>
           <TableItem/>
           <TableItem>50.2%</TableItem>
           <TableItem>77.2%</TableItem>
         </TableRow>
         <TableRow>
           <TableItem>Olives</TableItem>
           <TableItem/>
           <TableItem>24.9%</TableItem>
           <TableItem>55.9%</TableItem>
         </TableRow>
       </TableBody>
     </Table>
   </Layout>
 </Slide>
 <Slide transition={['spin', 'slide']} bgColor="tertiary">
   <Heading size={1} caps fit lineHeight={1.5} textColor="primary">
     Made with love in Seattle by
   </Heading>
   <Link href="http://www.formidable.com"><Image width="100%" src={images.logo}/></Link>
 </Slide> */
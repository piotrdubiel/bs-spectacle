[@bs.obj]
external makeBaseProps:
  (
    ~italic: Js.boolean=?,
    ~bold: Js.boolean=?,
    ~caps: Js.boolean=?,
    ~margin: string=?,
    ~padding: string=?,
    ~textColor: string=?,
    ~textSize: string=?,
    ~textAlign: string=?,
    ~textFont: string=?,
    ~bgColor: string=?,
    ~bgImage: string=?,
    ~bgSize: string=?,
    ~bgPosition: string=?,
    ~bgRepeat: string=?,
    ~bgDarken: float=?,
    ~overflow: string=?,
    ~height: string=?,
    unit
  ) =>
  _ =
  "";

let extendProps =
    (
      ~italic=?,
      ~bold=?,
      ~caps=?,
      ~margin=?,
      ~padding=?,
      ~textColor=?,
      ~textSize=?,
      ~textAlign=?,
      ~textFont=?,
      ~bgColor=?,
      ~bgImage=?,
      ~bgSize=?,
      ~bgPosition=?,
      ~bgRepeat=?,
      ~bgDarken=?,
      ~overflow=?,
      ~height=?,
      moreProps,
    ) =>
  Object.assign(
    Js.Obj.empty(),
    makeBaseProps(
      ~italic=?Types.to_js_boolean(italic),
      ~bold=?Types.to_js_boolean(bold),
      ~caps=?Types.to_js_boolean(caps),
      ~margin?,
      ~padding?,
      ~textColor?,
      ~textSize?,
      ~textAlign?,
      ~textFont?,
      ~bgColor?,
      ~bgImage?,
      ~bgSize?,
      ~bgPosition?,
      ~bgRepeat?,
      ~bgDarken?,
      ~overflow?,
      ~height?,
      (),
    ),
    moreProps,
  );

module type BaseComponent = {let reactClass: ReasonReact.reactClass;};

module MakeBaseComponent = (BaseComponent: BaseComponent) => {
  let make =
      (
        ~italic=?,
        ~bold=?,
        ~caps=?,
        ~margin=?,
        ~padding=?,
        ~textColor=?,
        ~textSize=?,
        ~textAlign=?,
        ~textFont=?,
        ~bgColor=?,
        ~bgImage=?,
        ~bgSize=?,
        ~bgPosition=?,
        ~bgRepeat=?,
        ~bgDarken=?,
        ~overflow=?,
        ~height=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=BaseComponent.reactClass,
      ~props=
        makeBaseProps(
          ~italic=?Types.to_js_boolean(italic),
          ~bold=?Types.to_js_boolean(bold),
          ~caps=?Types.to_js_boolean(caps),
          ~margin?,
          ~padding?,
          ~textColor?,
          ~textSize?,
          ~textAlign?,
          ~textFont?,
          ~bgColor?,
          ~bgImage?,
          ~bgSize?,
          ~bgPosition?,
          ~bgRepeat?,
          ~bgDarken?,
          ~overflow?,
          ~height?,
          (),
        ),
      children,
    );
};
(self.webpackChunk_N_E=self.webpackChunk_N_E||[]).push([[4416],{79367:function(e,t){var n,r,o;r=[e,t],n=function(e,t){"use strict";var n="function"===typeof Map?new Map:function(){var e=[],t=[];return{has:function(t){return e.indexOf(t)>-1},get:function(n){return t[e.indexOf(n)]},set:function(n,r){-1===e.indexOf(n)&&(e.push(n),t.push(r))},delete:function(n){var r=e.indexOf(n);r>-1&&(e.splice(r,1),t.splice(r,1))}}}(),r=function(e){return new Event(e,{bubbles:!0})};try{new Event("test")}catch(u){r=function(e){var t=document.createEvent("Event");return t.initEvent(e,!0,!1),t}}function o(e){if(e&&e.nodeName&&"TEXTAREA"===e.nodeName&&!n.has(e)){var t=null,o=null,i=null,a=function(){e.clientWidth!==o&&c()},l=function(t){window.removeEventListener("resize",a,!1),e.removeEventListener("input",c,!1),e.removeEventListener("keyup",c,!1),e.removeEventListener("autosize:destroy",l,!1),e.removeEventListener("autosize:update",c,!1),Object.keys(t).forEach((function(n){e.style[n]=t[n]})),n.delete(e)}.bind(e,{height:e.style.height,resize:e.style.resize,overflowY:e.style.overflowY,overflowX:e.style.overflowX,wordWrap:e.style.wordWrap});e.addEventListener("autosize:destroy",l,!1),"onpropertychange"in e&&"oninput"in e&&e.addEventListener("keyup",c,!1),window.addEventListener("resize",a,!1),e.addEventListener("input",c,!1),e.addEventListener("autosize:update",c,!1),e.style.overflowX="hidden",e.style.wordWrap="break-word",n.set(e,{destroy:l,update:c}),u()}function u(){var n=window.getComputedStyle(e,null);"vertical"===n.resize?e.style.resize="none":"both"===n.resize&&(e.style.resize="horizontal"),t="content-box"===n.boxSizing?-(parseFloat(n.paddingTop)+parseFloat(n.paddingBottom)):parseFloat(n.borderTopWidth)+parseFloat(n.borderBottomWidth),isNaN(t)&&(t=0),c()}function s(t){var n=e.style.width;e.style.width="0px",e.offsetWidth,e.style.width=n,e.style.overflowY=t}function d(e){for(var t=[];e&&e.parentNode&&e.parentNode instanceof Element;)e.parentNode.scrollTop&&t.push({node:e.parentNode,scrollTop:e.parentNode.scrollTop}),e=e.parentNode;return t}function p(){if(0!==e.scrollHeight){var n=d(e),r=document.documentElement&&document.documentElement.scrollTop;e.style.height="",e.style.height=e.scrollHeight+t+"px",o=e.clientWidth,n.forEach((function(e){e.node.scrollTop=e.scrollTop})),r&&(document.documentElement.scrollTop=r)}}function c(){p();var t=Math.round(parseFloat(e.style.height)),n=window.getComputedStyle(e,null),o="content-box"===n.boxSizing?Math.round(parseFloat(n.height)):e.offsetHeight;if(o<t?"hidden"===n.overflowY&&(s("scroll"),p(),o="content-box"===n.boxSizing?Math.round(parseFloat(window.getComputedStyle(e,null).height)):e.offsetHeight):"hidden"!==n.overflowY&&(s("hidden"),p(),o="content-box"===n.boxSizing?Math.round(parseFloat(window.getComputedStyle(e,null).height)):e.offsetHeight),i!==o){i=o;var a=r("autosize:resized");try{e.dispatchEvent(a)}catch(l){}}}}function i(e){var t=n.get(e);t&&t.destroy()}function a(e){var t=n.get(e);t&&t.update()}var l=null;"undefined"===typeof window||"function"!==typeof window.getComputedStyle?((l=function(e){return e}).destroy=function(e){return e},l.update=function(e){return e}):((l=function(e,t){return e&&Array.prototype.forEach.call(e.length?e:[e],(function(e){return o(e,t)})),e}).destroy=function(e){return e&&Array.prototype.forEach.call(e.length?e:[e],i),e},l.update=function(e){return e&&Array.prototype.forEach.call(e.length?e:[e],a),e}),t.default=l,e.exports=t.default},void 0===(o="function"===typeof n?n.apply(t,r):n)||(e.exports=o)},31934:function(e){e.exports=function(e,t,n){return((n=window.getComputedStyle)?n(e):e.currentStyle)[t.replace(/-(\w)/gi,(function(e,t){return t.toUpperCase()}))]}},58303:function(e,t,n){var r=n(31934);e.exports=function(e){var t=r(e,"line-height"),n=parseFloat(t,10);if(t===n+""){var o=e.style.lineHeight;e.style.lineHeight=t+"em",t=r(e,"line-height"),n=parseFloat(t,10),o?e.style.lineHeight=o:delete e.style.lineHeight}if(-1!==t.indexOf("pt")?(n*=4,n/=3):-1!==t.indexOf("mm")?(n*=96,n/=25.4):-1!==t.indexOf("cm")?(n*=96,n/=2.54):-1!==t.indexOf("in")?n*=96:-1!==t.indexOf("pc")&&(n*=16),n=Math.round(n),"normal"===t){var i=e.nodeName,a=document.createElement(i);a.innerHTML="&nbsp;","TEXTAREA"===i.toUpperCase()&&a.setAttribute("rows","1");var l=r(e,"font-size");a.style.fontSize=l,a.style.padding="0px",a.style.border="0px";var u=document.body;u.appendChild(a),n=a.offsetHeight,u.removeChild(a)}return n}},4857:function(e,t,n){"use strict";var r=this&&this.__extends||function(){var e=Object.setPrototypeOf||{__proto__:[]}instanceof Array&&function(e,t){e.__proto__=t}||function(e,t){for(var n in t)t.hasOwnProperty(n)&&(e[n]=t[n])};return function(t,n){function r(){this.constructor=t}e(t,n),t.prototype=null===n?Object.create(n):(r.prototype=n.prototype,new r)}}(),o=this&&this.__assign||Object.assign||function(e){for(var t,n=1,r=arguments.length;n<r;n++)for(var o in t=arguments[n])Object.prototype.hasOwnProperty.call(t,o)&&(e[o]=t[o]);return e},i=this&&this.__rest||function(e,t){var n={};for(var r in e)Object.prototype.hasOwnProperty.call(e,r)&&t.indexOf(r)<0&&(n[r]=e[r]);if(null!=e&&"function"===typeof Object.getOwnPropertySymbols){var o=0;for(r=Object.getOwnPropertySymbols(e);o<r.length;o++)t.indexOf(r[o])<0&&(n[r[o]]=e[r[o]])}return n};t.__esModule=!0;var a=n(67294),l=n(45697),u=n(79367),s=n(58303),d="autosize:resized",p=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.state={lineHeight:null},t.textarea=null,t.onResize=function(e){t.props.onResize&&t.props.onResize(e)},t.updateLineHeight=function(){t.textarea&&t.setState({lineHeight:s(t.textarea)})},t.onChange=function(e){var n=t.props.onChange;t.currentValue=e.currentTarget.value,n&&n(e)},t}return r(t,e),t.prototype.componentDidMount=function(){var e=this,t=this.props,n=t.maxRows,r=t.async;"number"===typeof n&&this.updateLineHeight(),"number"===typeof n||r?setTimeout((function(){return e.textarea&&u(e.textarea)})):this.textarea&&u(this.textarea),this.textarea&&this.textarea.addEventListener(d,this.onResize)},t.prototype.componentWillUnmount=function(){this.textarea&&(this.textarea.removeEventListener(d,this.onResize),u.destroy(this.textarea))},t.prototype.render=function(){var e=this,t=this.props,n=(t.onResize,t.maxRows),r=(t.onChange,t.style),l=(t.innerRef,t.children),u=i(t,["onResize","maxRows","onChange","style","innerRef","children"]),s=this.state.lineHeight,d=n&&s?s*n:null;return a.createElement("textarea",o({},u,{onChange:this.onChange,style:d?o({},r,{maxHeight:d}):r,ref:function(t){e.textarea=t,"function"===typeof e.props.innerRef?e.props.innerRef(t):e.props.innerRef&&(e.props.innerRef.current=t)}}),l)},t.prototype.componentDidUpdate=function(){this.textarea&&u.update(this.textarea)},t.defaultProps={rows:1,async:!1},t.propTypes={rows:l.number,maxRows:l.number,onResize:l.func,innerRef:l.any,async:l.bool},t}(a.Component);t.TextareaAutosize=a.forwardRef((function(e,t){return a.createElement(p,o({},e,{innerRef:t}))}))},54042:function(e,t,n){"use strict";var r=n(4857);t.Z=r.TextareaAutosize},16496:function(e){!function(){var t=["direction","boxSizing","width","height","overflowX","overflowY","borderTopWidth","borderRightWidth","borderBottomWidth","borderLeftWidth","borderStyle","paddingTop","paddingRight","paddingBottom","paddingLeft","fontStyle","fontVariant","fontWeight","fontStretch","fontSize","fontSizeAdjust","lineHeight","fontFamily","textAlign","textTransform","textIndent","textDecoration","letterSpacing","wordSpacing","tabSize","MozTabSize"],n="undefined"!==typeof window,r=n&&null!=window.mozInnerScreenX;function o(e,o,i){if(!n)throw new Error("textarea-caret-position#getCaretCoordinates should only be called in a browser");var a=i&&i.debug||!1;if(a){var l=document.querySelector("#input-textarea-caret-position-mirror-div");l&&l.parentNode.removeChild(l)}var u=document.createElement("div");u.id="input-textarea-caret-position-mirror-div",document.body.appendChild(u);var s=u.style,d=window.getComputedStyle?window.getComputedStyle(e):e.currentStyle,p="INPUT"===e.nodeName;s.whiteSpace="pre-wrap",p||(s.wordWrap="break-word"),s.position="absolute",a||(s.visibility="hidden"),t.forEach((function(e){p&&"lineHeight"===e?s.lineHeight=d.height:s[e]=d[e]})),r?e.scrollHeight>parseInt(d.height)&&(s.overflowY="scroll"):s.overflow="hidden",u.textContent=e.value.substring(0,o),p&&(u.textContent=u.textContent.replace(/\s/g,"\xa0"));var c=document.createElement("span");c.textContent=e.value.substring(o)||".",u.appendChild(c);var f={top:c.offsetTop+parseInt(d.borderTopWidth),left:c.offsetLeft+parseInt(d.borderLeftWidth),height:parseInt(d.lineHeight)};return a?c.style.backgroundColor="#aaa":document.body.removeChild(u),f}"undefined"!=typeof e.exports?e.exports=o:n&&(window.getCaretCoordinates=o)}()},65451:function(e,t,n){"use strict";n.d(t,{E:function(){return A}});var r=n(67294),o=n(12351),i=n(19946),a=n(32984),l=n(16723),u=n(61363),s=n(84575);var d,p=n(95389),c=n(39516),f=n(31591),h=n(23784),v=n(46045),m=n(18689),g=n(15466),y=n(73781),b=n(31147),w=n(64103),x=((d=x||{})[d.RegisterOption=0]="RegisterOption",d[d.UnregisterOption=1]="UnregisterOption",d);let E={0(e,t){let n=[...e.options,{id:t.id,element:t.element,propsRef:t.propsRef}];return{...e,options:(0,s.z2)(n,(e=>e.element.current))}},1(e,t){let n=e.options.slice(),r=e.options.findIndex((e=>e.id===t.id));return-1===r?e:(n.splice(r,1),{...e,options:n})}},R=(0,r.createContext)(null);function C(e){let t=(0,r.useContext)(R);if(null===t){let t=new Error(`<${e} /> is missing a parent <RadioGroup /> component.`);throw Error.captureStackTrace&&Error.captureStackTrace(t,C),t}return t}function T(e,t){return(0,a.E)(t.type,E,e,t)}R.displayName="RadioGroupContext";let z=(0,o.yV)((function(e,t){let{value:n,defaultValue:a,name:l,onChange:d,by:w=((e,t)=>e===t),disabled:x=!1,...E}=e,C=(0,y.z)("string"==typeof w?(e,t)=>{let n=w;return(null==e?void 0:e[n])===(null==t?void 0:t[n])}:w),[z,O]=(0,r.useReducer)(T,{options:[]}),S=z.options,[A,k]=(0,p.b)(),[L,F]=(0,c.f)(),_=`headlessui-radiogroup-${(0,i.M)()}`,H=(0,r.useRef)(null),N=(0,h.T)(H,t),[P,M]=(0,b.q)(n,d,a),W=(0,r.useMemo)((()=>S.find((e=>!e.propsRef.current.disabled))),[S]),D=(0,r.useMemo)((()=>S.some((e=>C(e.propsRef.current.value,P)))),[S,P]),I=(0,y.z)((e=>{var t;if(x||C(e,P))return!1;let n=null==(t=S.find((t=>C(t.propsRef.current.value,e))))?void 0:t.propsRef.current;return(null==n||!n.disabled)&&(null==M||M(e),!0)}));(0,f.B)({container:H.current,accept:e=>"radio"===e.getAttribute("role")?NodeFilter.FILTER_REJECT:e.hasAttribute("role")?NodeFilter.FILTER_SKIP:NodeFilter.FILTER_ACCEPT,walk(e){e.setAttribute("role","none")}});let j=(0,y.z)((e=>{let t=H.current;if(!t)return;let n=(0,g.r)(t),r=S.filter((e=>!1===e.propsRef.current.disabled)).map((e=>e.element.current));switch(e.key){case u.R.Enter:(0,m.g)(e.currentTarget);break;case u.R.ArrowLeft:case u.R.ArrowUp:if(e.preventDefault(),e.stopPropagation(),(0,s.jA)(r,s.TO.Previous|s.TO.WrapAround)===s.fE.Success){let e=S.find((e=>e.element.current===(null==n?void 0:n.activeElement)));e&&I(e.propsRef.current.value)}break;case u.R.ArrowRight:case u.R.ArrowDown:if(e.preventDefault(),e.stopPropagation(),(0,s.jA)(r,s.TO.Next|s.TO.WrapAround)===s.fE.Success){let e=S.find((e=>e.element.current===(null==n?void 0:n.activeElement)));e&&I(e.propsRef.current.value)}break;case u.R.Space:{e.preventDefault(),e.stopPropagation();let t=S.find((e=>e.element.current===(null==n?void 0:n.activeElement)));t&&I(t.propsRef.current.value)}}})),G=(0,y.z)((e=>(O({type:0,...e}),()=>O({type:1,id:e.id})))),Y=(0,r.useMemo)((()=>({registerOption:G,firstOption:W,containsCheckedOption:D,change:I,disabled:x,value:P,compare:C})),[G,W,D,I,x,P,C]),U={ref:N,id:_,role:"radiogroup","aria-labelledby":A,"aria-describedby":L,onKeyDown:j},B=(0,r.useMemo)((()=>({value:P})),[P]);return r.createElement(F,{name:"RadioGroup.Description"},r.createElement(k,{name:"RadioGroup.Label"},r.createElement(R.Provider,{value:Y},null!=l&&null!=P&&(0,m.t)({[l]:P}).map((([e,t])=>r.createElement(v._,{features:v.A.Hidden,...(0,o.oA)({key:e,as:"input",type:"radio",checked:null!=t,hidden:!0,readOnly:!0,name:e,value:t})}))),(0,o.sY)({ourProps:U,theirProps:E,slot:B,defaultTag:"div",name:"RadioGroup"}))))}));var O=(e=>(e[e.Empty=1]="Empty",e[e.Active=2]="Active",e))(O||{});let S=(0,o.yV)((function(e,t){let n=(0,r.useRef)(null),a=(0,h.T)(n,t),u=`headlessui-radiogroup-option-${(0,i.M)()}`,[s,d]=(0,p.b)(),[f,v]=(0,c.f)(),{addFlag:m,removeFlag:g,hasFlag:b}=function(e=0){let[t,n]=(0,r.useState)(e);return{addFlag:(0,r.useCallback)((e=>n((t=>t|e))),[t]),hasFlag:(0,r.useCallback)((e=>Boolean(t&e)),[t]),removeFlag:(0,r.useCallback)((e=>n((t=>t&~e))),[n]),toggleFlag:(0,r.useCallback)((e=>n((t=>t^e))),[n])}}(1),{value:x,disabled:E=!1,...R}=e,T=(0,r.useRef)({value:x,disabled:E});(0,l.e)((()=>{T.current.value=x}),[x,T]),(0,l.e)((()=>{T.current.disabled=E}),[E,T]);let{registerOption:z,disabled:O,change:S,firstOption:A,containsCheckedOption:k,value:L,compare:F}=C("RadioGroup.Option");(0,l.e)((()=>z({id:u,element:n,propsRef:T})),[u,z,n,e]);let _=(0,y.z)((e=>{var t;if((0,w.P)(e.currentTarget))return e.preventDefault();!S(x)||(m(2),null==(t=n.current)||t.focus())})),H=(0,y.z)((e=>{if((0,w.P)(e.currentTarget))return e.preventDefault();m(2)})),N=(0,y.z)((()=>g(2))),P=(null==A?void 0:A.id)===u,M=O||E,W=F(L,x),D={ref:a,id:u,role:"radio","aria-checked":W?"true":"false","aria-labelledby":s,"aria-describedby":f,"aria-disabled":!!M||void 0,tabIndex:M?-1:W||!k&&P?0:-1,onClick:M?void 0:_,onFocus:M?void 0:H,onBlur:M?void 0:N},I=(0,r.useMemo)((()=>({checked:W,disabled:M,active:b(2)})),[W,M,b]);return r.createElement(v,{name:"RadioGroup.Description"},r.createElement(d,{name:"RadioGroup.Label"},(0,o.sY)({ourProps:D,theirProps:R,slot:I,defaultTag:"div",name:"RadioGroup.Option"})))})),A=Object.assign(z,{Option:S,Label:p._,Description:c.d})},61757:function(e,t,n){"use strict";function r(e){return""===e?document.execCommand("delete"):document.execCommand("insertText",!1,e)}function o(e,t){var n=e.ownerDocument,o=n.activeElement;o!==e&&e.focus(),r(t)||function(e,t){e.setRangeText(t,e.selectionStart||0,e.selectionEnd||0,"end"),e.dispatchEvent(new InputEvent("input",{data:t,inputType:"insertText"}))}(e,t),o===n.body?e.blur():o instanceof HTMLElement&&o!==e&&o.focus()}function i(e){return e.value.slice(e.selectionStart,e.selectionEnd)}n.d(t,{$T:function(){return o},Mf:function(){return i}})}}]);
//# sourceMappingURL=4416-8598478ad00101bb.js.map
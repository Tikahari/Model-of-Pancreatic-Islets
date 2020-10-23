(function(e,n){"object"==typeof exports&&"undefined"!=typeof module?n(exports,require("react"),require("prop-types")):"function"==typeof define&&define.amd?define(["exports","react","prop-types"],n):n(e.ReactAsyncComponent={},e.React,e.PropTypes)})(this,(function(e,n,t){"use strict";var o="default"in n?n.default:n;t=t&&t.hasOwnProperty("default")?t.default:t;var r="function"==typeof Symbol&&"symbol"==typeof Symbol.iterator?function(e){return typeof e}:function(e){return e&&"function"==typeof Symbol&&e.constructor===Symbol&&e!==Symbol.prototype?"symbol":typeof e},s=function(e,n){if(!(e instanceof n))throw new TypeError("Cannot call a class as a function")},i=(function(){function e(e,n){for(var t=0;t<n.length;t++){var o=n[t];o.enumerable=o.enumerable||!1,o.configurable=!0,"value"in o&&(o.writable=!0),Object.defineProperty(e,o.key,o)}}return function(n,t,o){return t&&e(n.prototype,t),o&&e(n,o),n}})(),u=Object.assign||function(e){for(var n=1;n<arguments.length;n++){var t=arguments[n];for(var o in t)Object.prototype.hasOwnProperty.call(t,o)&&(e[o]=t[o])}return e},a=function(e,n){if("function"!=typeof n&&null!==n)throw new TypeError("Super expression must either be null or a function, not "+typeof n);e.prototype=Object.create(n&&n.prototype,{constructor:{value:e,enumerable:!1,writable:!0,configurable:!0}}),n&&(Object.setPrototypeOf?Object.setPrototypeOf(e,n):e.__proto__=n)},c=function(e,n){if(!e)throw new ReferenceError("this hasn't been initialised - super() hasn't been called");return!n||"object"!=typeof n&&"function"!=typeof n?e:n},l=function(){var e=0,n={},t={};return{getNextId:function(){return e+=1},resolved:function(e){n[e]=!0},failed:function(e,n){t[e]=n},getState:function(){return{resolved:Object.keys(n).reduce((function(e,n){return Object.assign(e,(r=!0,(o=n)in(t={})?Object.defineProperty(t,o,{value:r,enumerable:!0,configurable:!0,writable:!0}):t[o]=r,t));var t,o,r}),{}),errors:t}}}},d=(function(e){function n(){return s(this,n),c(this,(n.__proto__||Object.getPrototypeOf(n)).apply(this,arguments))}return a(n,e),i(n,[{key:"componentWillMount",value:function(){this.asyncContext=this.props.asyncContext||l(),this.rehydrateState=this.props.rehydrateState}},{key:"getChildContext",value:function(){var e=this;return{asyncComponents:{getNextId:this.asyncContext.getNextId,resolved:this.asyncContext.resolved,failed:this.asyncContext.failed,shouldRehydrate:function(n){var t=e.rehydrateState.resolved[n];return delete e.rehydrateState.resolved[n],t},getError:function(n){return e.rehydrateState.errors&&e.rehydrateState.errors[n]}}}}},{key:"render",value:function(){return o.Children.only(this.props.children)}}]),n})(n.Component);d.propTypes={children:t.node.isRequired,asyncContext:t.shape({getNextId:t.func.isRequired,resolved:t.func.isRequired,failed:t.func.isRequired,getState:t.func.isRequired}),rehydrateState:t.shape({resolved:t.object})},d.defaultProps={asyncContext:void 0,rehydrateState:{resolved:{}}},d.childContextTypes={asyncComponents:t.shape({getNextId:t.func.isRequired,resolved:t.func.isRequired,failed:t.func.isRequired,shouldRehydrate:t.func.isRequired,getError:t.func.isRequired}).isRequired};var f=["resolve","defer","boundary"];e.AsyncComponentProvider=d,e.createAsyncContext=l,e.asyncComponent=function(e){var n,l,d=e.name,p=e.resolve,y=e.autoResolveES2015Default,v=void 0===y||y,h=e.serverMode,m=void 0===h?"resolve":h,C=e.LoadingComponent,b=e.ErrorComponent;if(-1===f.indexOf(m))throw new Error("Invalid serverMode provided to asyncComponent");var g=["node","browser"].indexOf(e.env)>-1?e.env:"undefined"==typeof window?"node":"browser",x={id:null,module:null,error:null,resolver:null,resolving:!1,asyncComponents:null,asyncComponentsAncestor:null};return l=n=(function(e){function n(){return s(this,n),c(this,(n.__proto__||Object.getPrototypeOf(n)).apply(this,arguments))}return a(n,e),i(n,[{key:"getChildContext",value:function(){return{asyncComponentsAncestor:null==x.asyncComponents?null:{isBoundary:"boundary"===m}}}},{key:"componentWillMount",value:function(){null!=this.context.asyncComponents&&(x.asyncComponents=this.context.asyncComponents,x.asyncComponentsAncestor=this.context.asyncComponentsAncestor,x.id||(x.id=this.context.asyncComponents.getNextId()))}},{key:"bootstrap",value:function(){var e=this,n=function(){return e.resolveModule().then((function(e){return void 0!==e&&void 0}))};if("browser"===g){var t=x.asyncComponents,o=t.shouldRehydrate,r=(0,t.getError)(x.id);return r?(x.error=r,!1):!!o(x.id)&&n()}var s=null!=x.asyncComponentsAncestor&&x.asyncComponentsAncestor.isBoundary;return"defer"!==m&&!s&&n()}},{key:"componentDidMount",value:function(){null!=x.module||null!=x.error||x.resolving||"undefined"==typeof window||this.resolveModule()}},{key:"resolveModule",value:function(){var e=this;return(function(){if(null==x.resolver){x.resolving=!0;try{x.resolver=Promise.resolve(p())}catch(e){x.resolver=Promise.reject(e)}}return x.resolver})().then((function(e){return null!=x.asyncComponents&&x.asyncComponents.resolved(x.id),x.module=e,x.error=null,x.resolving=!1,e})).catch((function(e){var n={message:e.message,stack:e.stack};null!=x.asyncComponents&&x.asyncComponents.failed(x.id,n),x.error=n,x.resolving=!1,b||console.error(n)})).then((function(n){if(!e.unmounted)return e.context.reactAsyncBootstrapperRunning||"browser"!==g||e.forceUpdate(),n}))}},{key:"componentWillUnmount",value:function(){this.unmounted=!0}},{key:"render",value:function(){var e=x.module,n=x.error;if(n)return b?o.createElement(b,u({},this.props,{error:n})):null;var t,s=(t=e,v&&null!=t&&("function"==typeof t||"object"===(void 0===t?"undefined":r(t)))&&t.default?t.default:t);return s?o.createElement(s,this.props):C?o.createElement(C,this.props):null}}]),n})(o.Component),n.displayName=d||"AsyncComponent",n.contextTypes={asyncComponentsAncestor:t.shape({isBoundary:t.bool}),asyncComponents:t.shape({getNextId:t.func.isRequired,resolved:t.func.isRequired,shouldRehydrate:t.func.isRequired})},n.childContextTypes={asyncComponentsAncestor:t.shape({isBoundary:t.bool})},l},Object.defineProperty(e,"__esModule",{value:!0})}));
//# sourceMappingURL=react-async-component.min.js-vflqFZNU-.map
define(["require","exports","tslib","modules/core/browser","modules/core/uri"],(function(e,t,r,n,o){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),n=r.__importStar(n),t.getSignInAndContinueUrl=function(e){void 0===e&&(e={});var t={cont:e.cont?e.cont:n.get_href()};return e.register_cont&&(t.register_cont=e.register_cont),e.signupTag&&(t.signup_tag=e.signupTag),new o.URI({path:"/login",query:t}).toString()}}));
//# sourceMappingURL=utils.min.js-vflkwymD4.map
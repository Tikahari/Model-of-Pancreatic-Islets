define(["exports"],(function(e){"use strict";e.default=function(){for(var e=arguments.length,n=Array(e),t=0;t<e;t++)n[t]=arguments[t];var r="function"!=typeof n[n.length-1]&&n.pop(),o=n;if(void 0===r)throw new TypeError("The initial state may not be undefined. If you do not want to set a value for this reducer, you can use null instead of undefined.");return function(e,n){for(var t=arguments.length,u=Array(t>2?t-2:0),i=2;i<t;i++)u[i-2]=arguments[i];var a=void 0===e,f=void 0===n;return a&&f&&r?r:o.reduce((function(e,t){return t.apply(void 0,[e,n].concat(u))}),a&&!f&&r?r:e)}},Object.defineProperty(e,"__esModule",{value:!0})}));
//# sourceMappingURL=reduce-reducers.js-vfldIpFSe.map

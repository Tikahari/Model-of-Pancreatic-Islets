define(["require","exports"],(function(o,n){"use strict";Object.defineProperty(n,"__esModule",{value:!0}),n.LoggerBehavior=function(o){var n=o.loggingFunction,e=void 0===n?function(){}:n,t=o.logToConsole,i=void 0!==t&&t,r=o.actionsToLog,c=void 0===r?[]:r;return(function(){function o(){var o=this;c.forEach((function(n){var t=n.action,r=n.parser;t.watch((function(n,t){var c=o.getState(),a=r(t,c);a&&e(a),i&&console.log(a)}))}))}return o.displayName="Logger",o})()}}));
//# sourceMappingURL=logger_behavior.min.js-vflSUKVYP.map
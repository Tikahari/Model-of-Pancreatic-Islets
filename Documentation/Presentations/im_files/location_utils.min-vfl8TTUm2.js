define(["require","exports","tslib","modules/clean/rondo/router/types"],(function(t,r,n,e){"use strict";Object.defineProperty(r,"__esModule",{value:!0}),r.endsWith=function(t,r){return r?r.charAt(r.length-1)!==t?r+t:r:""},r.endsWithPath=function(t){return r.endsWith("/",t)},r.notStartWith=function(t,r){return r?r.charAt(0)===t?r.substring(1):r:""},r.notStartWithPath=function(t){return r.notStartWith("/",t)},r.startsWith=function(t,r){return r?r.charAt(0)!==t?t+r:r:""},r.startsWithHash=function(t){return r.startsWith("#",t)},r.startsWithSearch=function(t){return r.startsWith("?",t)},r.combinePath=function(t,n){return n&&0!==t.indexOf(n)?t?""+r.endsWithPath(n)+r.notStartWithPath(t):n:t},r.locationToPath=function(t,a,s,i){switch(t){case e.RouterType.Hash:return n.__assign(n.__assign({},a),{hash:r.startsWithHash(s)});case e.RouterType.Browser:return n.__assign(n.__assign({},a),{pathname:r.combinePath(s,i)})}},r.locationToSearch=function(t,e,a){if(!e)return"";var s=e;if(a){var i=r.searchToParams(t);s=n.__assign(n.__assign({},i),e)}var h=Object.keys(s).map((function(t){return s[t]?t+"="+encodeURI(s[t]):t})).join("&");return h&&"?"+h},r.searchToParams=function(t){var r={};t&&t.length>1&&(r=t.split("&").reduce((function(t,r){var e=n.__read(r.split("="),2),a=e[0],s=e[1];return t[a.replace(/^\?/,"")]=s?decodeURI(s):"",t}),{}));return r},r.locationToRelativePath=function(t,n,a){var s=n.pathname,i=n.hash,h=n.search;switch(t){case e.RouterType.Hash:return i&&"#"===i.charAt(0)?i.substring(1):i;case e.RouterType.Browser:return a&&s?""+r.combinePath(s,a)+r.startsWithSearch(h)+r.startsWithHash(i):s}}}));
//# sourceMappingURL=location_utils.min.js-vfl-cC8ia.map
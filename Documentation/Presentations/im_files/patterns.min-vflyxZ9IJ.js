define(["require","exports"],(function(e,r){"use strict";Object.defineProperty(r,"__esModule",{value:!0}),r.singleMatch=function(e){return function(r){return e(r[1])}},r.camelCaseToUnderscorePattern=function(e){return e.replace(/([a-zA-Z])(?=[A-Z])/g,(function(e){return e+"_"})).toUpperCase()},r.lowerFirstCharacterPattern=function(e){return""+(e.length>0?e[0].toLowerCase():"")+(e.length>1?e.substr(1):"")},r.camelCaseToUnderscoreSingleMatch=r.singleMatch(r.camelCaseToUnderscorePattern),r.lowerFirstCharacterSingleMatch=r.singleMatch(r.lowerFirstCharacterPattern)}));
//# sourceMappingURL=patterns.min.js-vfl9e8LAx.map
define(["require","exports","tslib","classnames","react","modules/core/i18n"],(function(e,t,a,l,s,c){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),l=a.__importDefault(l),s=a.__importDefault(s),t.CategoryHeader=function(e){var t=e.category,a=t.activities,n=t.checked,r=t.label,u=a.length,i=n?u:a.filter((function(e){return e.checked})).length;return s.default.createElement("h2",{ref:e.setElement},s.default.createElement("span",{className:"title"},r),s.default.createElement("span",{className:"items-count"},"(",u,")"),s.default.createElement("span",{className:l.default("selected-items-count",{"has-items":i>0})},c.intl.formatMessage({id:"hIWeAV",defaultMessage:"{count, plural, one{{count} selected} other{{count} selected}}"},{count:i})))}}));
//# sourceMappingURL=category_header.min.js-vflWtEUR6.map
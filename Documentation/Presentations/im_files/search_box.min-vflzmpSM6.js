define(["require","exports","tslib","react","modules/core/i18n","spectrum/icon_global"],(function(e,a,t,r,l,s){"use strict";Object.defineProperty(a,"__esModule",{value:!0}),r=t.__importDefault(r);var c=function(e){var a=e.key,t=e.currentTarget,r=t.selectionStart,l=t.selectionEnd;"Backspace"===a&&0===r&&0===l&&e.preventDefault()};a.SearchBox=function(e){var a="activity-search-box",i=l.intl.formatMessage({id:"9ug4JK",defaultMessage:"Search activities"});return r.default.createElement("div",{className:"search-box"},r.default.createElement("label",{htmlFor:a},r.default.createElement("div",{className:"search-title"},i),r.default.createElement(s.IconGlobal,{name:"search",className:"search-icon"}),r.default.createElement("input",t.__assign({autoFocus:!0,id:a,type:"text",placeholder:l.intl.formatMessage({id:"rGwHrj",defaultMessage:"Created shared folder, failed to sign in, reset password"}),"aria-label":i,onKeyDown:c},e))))}}));
//# sourceMappingURL=search_box.min.js-vfl92bw8o.map
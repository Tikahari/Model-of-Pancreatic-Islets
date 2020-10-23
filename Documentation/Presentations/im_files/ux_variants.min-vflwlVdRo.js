define(["require","exports"],(function(t,a){"use strict";Object.defineProperty(a,"__esModule",{value:!0}),a.ADOBE_TARGET_MATCHER_CONFIG_DATA_ATTRIBUTE="data-uxa-matcher-configs",a.ADOBE_TARGET_FEATURE_CONFIG_DATA_ATTRIBUTE="data-uxa-variant-tokens";a.DROPBOX_VARIANTS_ISSUER="https://dropbox.com/ux_analytics";var r=0;a.resetMetaTagConfigQueryCount=function(){r=0},a.addConfigsFromDOM=function(t){void 0===t&&(t=!1);var e=function(t,a){var r=[],e=document.head.querySelectorAll("meta["+t+"]");return e?(Array.prototype.forEach.call(e,(function(e){try{var n=e.getAttribute(t);if(!n)return;a?r.push.apply(r,JSON.parse(n)):r.push(n)}catch(t){}})),r):[]};if(!(t&&r>1||!t&&r)){r++;var i=e(a.ADOBE_TARGET_MATCHER_CONFIG_DATA_ATTRIBUTE,!0),s=e(a.ADOBE_TARGET_FEATURE_CONFIG_DATA_ATTRIBUTE,!1);if(i.length&&s.length)n({variant_tokens:s.join(","),matchers:i})}};a.addMatchedVariantsToEvent=function(t){var r=function(t,a){return void 0===t||(function(t,a){if(void 0===t)return!0;var r=t;for(var e in r)if(String(a[e])!==String(r[e]))return!1;return!0})(t.extra,a.extra)};if("undefined"!=typeof self&&self){var e;a.addConfigsFromDOM();var n,i,s,o=self._DBX_UX_variants_configStore,f={};if(t&&o&&o.matchers&&t.eventName&&(e=o.matchers[t.eventName]))for(var _ in e)if(o.assignments&&e.hasOwnProperty(_)){var v=e[_],u=o.assignments[v.feature_name];u&&void 0===f[u.variantToken]&&r(v.like,t)&&(t.extra||(t.extra={}),n=u.variantToken,i=t.extra,s=void 0,i[s=n.startsWith("adobetarget")?"adobe_target_variants":"variants"]?i[s]+=","+n:i[s]=n,f[u.variantToken]=!0)}}};var e=function(t){return t.startsWith("adobetarget:")?(function(t){for(var a=[],r=0,e=t.split(",");r<e.length;r++){var n=e[r];try{var i=n.split(":"),s=i[0],o=i[1],f=i[2];a.push([s+":"+o,f])}catch(t){continue}}return a})(t):(function(t){var r=function(t){return decodeURIComponent(escape(t))},e=t.split(".").map((function(t){return atob(t.split("_").join("/").split("-").join("+"))})),n=e[0],i=e[1];if(e[2]&&"JWT"===JSON.parse(r(n)).typ){var s=JSON.parse(r(i)),o=s.variants;if(s.iss===a.DROPBOX_VARIANTS_ISSUER){for(var f=[],_=0,v=o.split(",");_<v.length;_++){var u=v[_];f.push(u.split(":"))}return f}}})(t)};function n(t){if(t){self._DBX_UX_variants_configStore=self._DBX_UX_variants_configStore||{};var a=self._DBX_UX_variants_configStore,r=t.variant_tokens,n=t.matchers;if(r)for(var i=0,s=r.split(",");i<s.length;i++){var o=s[i],f=e(o);if(f)for(var _=0,v=f;_<v.length;_++){var u=v[_],c=u[0],T=u[1];a.assignments=a.assignments||{},a.assignments[c]={variant:T,variantToken:o}}}if(n)for(var l=0,g=n;l<g.length;l++){var m=g[l];a.matchers=a.matchers||{};var p=m.event_name;a.matchers[p]=a.matchers[p]||{};var A={feature_name:m.feature_name,event_name:p,is_pre_tti:m.is_pre_tti,like:m.like},h=JSON.stringify(A);a.matchers[p][h]=A}}}a.addConfig=n,a.getVariant=function(t){var a=self._DBX_UX_variants_configStore;return(a&&a.assignments&&a.assignments[t]||{}).variant||"OFF"}}));
//# sourceMappingURL=ux_variants.min.js-vflfPWadN.map
define(["require","exports","tslib","external/lodash","rondo/v1/metadata/convention"],(function(t,e,a,n,r){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),n=a.__importStar(n),e.Metadata="__Metadata__",e.MetadataKeys="__MetadataKeys__";var i="__This__",d=function(t){return void 0===t?i:t},u=function(t){return t===i?void 0:t},o=function(t,e,a,r){var i,u;return void 0===t&&(t={}),e=d(e),a=d(a),t[e]=t.hasOwnProperty(e)?n.merge(t[e],((i={})[a]=r,i)):((u={})[a]=r,u),t},s=function(t){return!!t[e.Metadata]};e.setMetadata=function(t,a,n,r){return t[e.Metadata]=o(t[e.Metadata],a,n,r),t[e.MetadataKeys]=o(t[e.MetadataKeys],n,a,r),t[e.MetadataKeys][n][d(a)]},e.getMetadata=function(t,a,n){if(void 0===a&&(a=i),(function(t,a){return void 0===a&&(a=i),s(t)&&!!t[e.Metadata][a]})(t,a))return t[e.Metadata][a][n]},e.getMetadataEntries=function(t,a,d){var o=d?r.entriesByConvention(t,d):{};if(!s(t)||!t[e.MetadataKeys].hasOwnProperty(a))return n.values(o);var c=function(t,e){return n.isArray(t)&&n.isArray(e)?t.concat(e):n.isObject(t)&&n.isObject(e)?void 0:n.isUndefined(e)?t:e},v=t[e.MetadataKeys][a],M=Object.keys(v).reduce((function(e,r){if(e[r]){var d=e[r].value,o=v[r];e[r].value=(s=d,M=o,f=n.isArray(s)&&n.isArray(M),y=n.isObject(s)&&n.isObject(M),f||y?n.mergeWith(d,o,c):n.isUndefined(o)?d:o)}else e[r]={target:t,key:u(r),meta:a,element:r===i?t:t[r],value:v[r]};var s,M,f,y;return e}),o);return n.values(M)},e.getMetadataEntry=function(t,a,n){var r=e.getMetadataEntries(t,a,n);return r.length>0?r[0]:void 0},e.getMetadataEntriesElements=function(t,a,n){return e.getMetadataEntries(t,a,n).map((function(t){return t.element}))},e.getMetadataEntryElement=function(t,a,n){var r=e.getMetadataEntry(t,a,n);return r?r.element:void 0}}));
//# sourceMappingURL=entry.min.js-vflhn05oe.map
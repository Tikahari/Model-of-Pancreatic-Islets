define(["require","exports","tslib","external/lodash"],(function(e,r,t,n){"use strict";Object.defineProperty(r,"__esModule",{value:!0}),n=t.__importStar(n);function i(e){return"[object Date]"===Object.prototype.toString.call(e)}r.immutableMerge=function(e,a){if(e===a)return e;if(n.isArray(e))return(function(e,t){if(n.isArray(t)){for(var i=[],a=e.length===t.length,o=0;o<t.length;o++)i[o]=e.length<o+1?t[o]:r.immutableMerge(e[o],t[o]),a=a&&e.length>o&&i[o]===e[o];return a?e:i}return void 0!==t?t:e})(e,a);if((function(e){try{return Map.prototype.has.call(e),!0}catch(e){return!1}})(a)||(function(e){try{return Set.prototype.has.call(e),!0}catch(e){return!1}})(a))return a;if(i(e)||i(a)){if(!i(e)||!i(a)){if(void 0===e||void 0===a)return a;if(console)console.warn("Date in non Date field"),console.trace();else try{throw new Error("Date in non Date field")}catch(e){}return a}return e.getTime()===a.getTime()?e:a}return n.isObject(e)?(function(e,i){var a,o,l,u;if(n.isObject(i)&&!n.isArray(i)&&!n.isFunction(i)&&!n.isString(i)){var c={},s=Object.keys(e),f=Object.keys(i),g=!0;try{for(var h=t.__values(f),v=h.next();!v.done;v=h.next()){var y=v.value,_=s.indexOf(y);_>=0?(c[y]=r.immutableMerge(e[y],i[y]),s.splice(_,1),g=g&&c[y]===e[y]):(c[y]=i[y],g=!1)}}catch(e){a={error:e}}finally{try{v&&!v.done&&(o=h.return)&&o.call(h)}finally{if(a)throw a.error}}g=g&&0===s.length;try{for(var d=t.__values(s),b=d.next();!b.done;b=d.next()){var m=b.value;c[m]=e[m]}}catch(e){l={error:e}}finally{try{b&&!b.done&&(u=d.return)&&u.call(d)}finally{if(l)throw l.error}}return g?e:c}return void 0!==i?i:e})(e,a):a};var a=function(e,r,n){var i,o;if(1===n.length)return t.__assign(t.__assign({},e),((i={})[n[0]]=r,i));var l=a(e[n[0]],r,n.slice(1));return t.__assign(t.__assign({},e),((o={})[n[0]]=l,o))};r.immutableSet=function(e,i,o){var l=0===o.length?e:n.get(e,o),u=r.immutableMerge(l,i);return u===l?e:0===o.length?t.__assign(t.__assign({},e),u):a(e,u,o)}}));
//# sourceMappingURL=immutable_set.min.js-vflT918lu.map
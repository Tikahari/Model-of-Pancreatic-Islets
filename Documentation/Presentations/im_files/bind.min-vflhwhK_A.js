define(["require","exports","tslib","external/lodash","rondo/v1/actions"],(function(r,n,e,t,o){"use strict";Object.defineProperty(n,"__esModule",{value:!0}),t=e.__importStar(t);var i=function(r,n){return function(){for(var t=[],o=0;o<arguments.length;o++)t[o]=arguments[o];return n(r.apply(void 0,e.__spread(t)))}},a=function(r,n,u){var s,c;void 0===u&&(u={});var l={};try{for(var f=e.__values(Object.keys(r)),v=f.next();!v.done;v=f.next()){var _=v.value,d=r[_];t.isFunction(d)?l[_]=o.isActionCreator(d)?d:i(d,n):t.isObject(d)&&(l[_]=a(d,n))}}catch(r){s={error:r}}finally{try{v&&!v.done&&(c=f.return)&&c.call(f)}finally{if(s)throw s.error}}return e.__assign(e.__assign({},u),l)};n.bindActionCreators=function(r){return function(n){return a(r,n)}}}));
//# sourceMappingURL=bind.min.js-vfloZmIIS.map
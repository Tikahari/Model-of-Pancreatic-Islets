define(["require","exports","tslib","external/lodash","redux-actions","rondo/v1/metadata_redux/action/metadata"],(function(e,t,n,i,o,r){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),i=n.__importStar(i),t.upsertAction=function(e,t,n,i,o,r){void 0===i&&(i={SLICE:{},NO_SLICE:{}}),void 0===r&&(r=e),i.SLICE[t]=o?[n,o]:n,r.actions=i},t.createActions=function(e,t,n){return void 0===t&&(t=e),void 0===n&&(n={SLICE:{},NO_SLICE:{}}),r.getActionEntries(e).reduce((function(e,n){var o=n.element,r=n.value,c=r.actionType,a=r.metaCreator,u=r.useSlice?e.SLICE:e.NO_SLICE;if(i.isFunction(o)){var s=o.bind(t);u[c]=a?[s,a]:s}return e}),n)},t.pathAction=function(e,t){return e.concat(t).join("/")};t.createActionCreators=function(e,n,i){return void 0===n&&(n=[]),void 0===i&&(i=e),r.getActionEntries(e).forEach((function(e){var r=e.element,c=e.key,a=e.value,u=a.actionType,s=a.metaCreator,d=a.useSlice?t.pathAction(n,u):u;i[(function(e){return"create"+e[0].toUpperCase()+e.substring(1)})(c)]=s?o.createAction(d,r.bind(i),s):o.createAction(d,r)}))}}));
//# sourceMappingURL=create.min.js-vflq9NQiT.map
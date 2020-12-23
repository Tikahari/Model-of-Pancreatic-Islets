define(["require","exports","tslib","history","rondo/v1/index","modules/clean/rondo/router/types","modules/clean/rondo/router/location_utils","modules/clean/rondo/router/router_path_behavior"],(function(o,t,e,r,a,i,n,c){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),t.RouterBehavior=function(o){var t=o.routerType,s=void 0===t?i.RouterType.Browser:t,h=o.basePath,u=void 0===h?"/":h,l=(function(){function o(){this.initialState=function(){var o=r.createHistory();return{history:o,location:o.getCurrentLocation(),routing:{routerType:s,basePath:u}}},this.search=a.createSelector((function(o){var t=o.location.search;return n.searchToParams(t)})),this.actionLocationChange=a.createAction().handle((function(o,t){return{location:t}})),this.actionLocationPush=a.createAction().watch((function(o,t){var r=o.history,a=o.location,i=t.url,c=void 0===i?n.locationToRelativePath(s,a):i,h=t.absolute,l=t.search,d=t.merge,v=void 0!==d&&d;if(h)return r.push(c);var f=n.locationToSearch(a.search,l,v);return r.push(n.locationToPath(s,e.__assign(e.__assign({},a),{search:f}),c,u))})),this.actionLocationReplace=a.createAction().watch((function(o,t){var r=o.history,a=o.location,i=t.url,c=t.absolute,h=t.search,l=t.merge;if(c)return r.replace(i);var d=n.locationToSearch(a.search,h,l);return r.replace(n.locationToPath(s,e.__assign(e.__assign({},a),{search:d}),i,u))})),this.actionLocationGo=a.createAction().watch((function(o,t){o.history.go(t)})),this.actionLocationGoBack=a.createAction().watch((function(o){o.history.goBack()})),this.actionLocationGoForward=a.createAction().watch((function(o){o.history.goForward()})),a.extendBehavior(this,c.RouterPathBehavior)}return o.prototype.ready=function(o){var t=this;o.history.listen((function(o){t.actionLocationChange(o)}))},o.displayName="RouterBehavior",o})();return a.behavior(l)}}));
//# sourceMappingURL=router_behavior.min.js-vfl9fW698.map
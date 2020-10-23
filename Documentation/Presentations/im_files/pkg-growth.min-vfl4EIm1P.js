define("modules/clean/growth/gating",["require","exports","tslib","modules/clean/ajax"],(function(t,e,r,n){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),(function(t){t.BASIC="BASIC",t.PLUS="PLUS",t.PRO="PRO"})(e.GatingSku||(e.GatingSku={})),e.inactiveGatingStatus={is_active:!1,variant:"OFF"};var i=(function(){function t(){this.cache={}}return t.prototype.clear=function(){this.cache={}},t.prototype.has=function(t,e){return!!this.get(t,e)},t.prototype.get=function(t,e){return this.cache[t]&&this.cache[t][e]},t.prototype.set=function(t,e,r){return this.cache[t]=this.cache[t]||{},this.cache[t][e]=r,r},t})();function o(t,e,i){return void 0===i&&(i={}),Promise.resolve().then((function(){return n.SilentBackgroundRequest(r.__assign({url:"/growth/gating_check",subject_user:t.id,data:{experiment:e}},i))})).then((function(t){return JSON.parse(t)}))}function c(t,r,n,i){return void 0===n&&(n={}),void 0===i&&(i=!1),i?e.gatingCache.has(t.id,r)?e.gatingCache.get(t.id,r):e.gatingCache.set(t.id,r,o(t,r,n)):o(t,r,n)}e.gatingCache=new i,e.gatingRequest=o,e.growthPrecacheGating=function(t,e,r){return void 0===r&&(r={}),c(t,e,r,!0)},e.growthCheckGating=c,e.growthCheckBasicUserGating=function(t,r,n){return void 0===n&&(n={}),"personal"!==t.role||t.paid?Promise.resolve(e.inactiveGatingStatus):c(t,r,n)}})),define("modules/clean/growth/user_action/tracker",["require","exports","tslib","react","hoist-non-react-statics","modules/clean/api_v2/user_client","modules/clean/react/helpers"],(function(t,e,r,n,i,o,c){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),n=r.__importStar(n),i=r.__importDefault(i);var s=(function(){function t(t,e){this.userId=t,this.timers={},e&&e.project&&(this.project=e.project),e&&e.client?this.client=e.client.ns("growth"):this.client=(new o.UserApiV2Client).ns("growth")}return t.prototype.startTimer=function(t){this.timers[t]={start:Date.now(),end:0}},t.prototype.stopTimer=function(t){this.timers[t]&&!this.timers[t].end&&(this.timers[t].end=Date.now())},t.prototype.clearTimer=function(t){delete this.timers[t]},t.prototype.getDuration=function(t){return this.timers[t]?this.timers[t].end?this.timers[t].end-this.timers[t].start:Date.now()-this.timers[t].start:0},t.prototype.track=function(t,e){return void 0===e&&(e={}),this.client.rpc("track_user_action",{project:this.project,action:t,duration:this.getDuration(t),extra:JSON.stringify(e.extra||{}),endpoint:e.endpoint||void 0},{subjectUserId:this.userId})},t})();e.GrowthUserActionTracker=s,e.withGrowthTracking=function(t,e){return function(o){var a=(function(i){function a(e){var r=i.call(this,e)||this;return r.tracker=new s(r.props.user.id,{project:t}),r.track=r.tracker.track.bind(r.tracker),r}return r.__extends(a,i),a.prototype.componentDidMount=function(){e&&e.mount&&this.tracker.track(e.mount)},a.prototype.componentWillUnmount=function(){e&&e.unmount&&this.tracker.track(e.unmount)},a.prototype.render=function(){return n.createElement(o,r.__assign({track:this.track,tracker:this.tracker},this.props))},a.displayName="WithGrowthTracking("+c.getDisplayName(o),a})(n.Component);return i.default(a,o)}}}));
//# sourceMappingURL=pkg-growth.min.js-vflgfzxha.map
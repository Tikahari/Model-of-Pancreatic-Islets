define(["require","exports","tslib","rondo/v1/index"],(function(e,t,n,o){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),t.ResetStateBehavior=function(e){var t=e.resetAction,r=e.resetTo,i=(function(){function e(){}return e.prototype.handleActionOpen=function(e){var t={};return r?t=r():this.composerBehavior&&(t=this.composerBehavior.createReducer()(void 0,{type:"INIT"})),n.__assign(n.__assign({},e),t)},e.displayName="ResetState",n.__decorate([o.handleAction(t)],e.prototype,"handleActionOpen",null),e})();return o.behavior(i)}}));
//# sourceMappingURL=reset_state_behavior.min.js-vflxZBFud.map
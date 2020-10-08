define(["require","exports","tslib","external/lodash","redux-actions","rondo/v1/invariant","rondo/v1/metadata_redux","rondo/v1/metadata","rondo/v1/actions/types","rondo/v1/behavior/handle","rondo/v1/behavior/action_watcher","rondo/v1/behavior/saga_handler","redux-saga"],(function(e,t,n,r,a,i,o,c,s,u,d,f,h){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=n.__importStar(r);var v=h.effects.takeEvery,l=h.effects.takeLatest,p=h.effects.takeLeading,b=(function(){function e(r){var c=this;this.deferredCallbacks=[],this.subscribedActions=[],this.isReady=function(){return c.baseAction?c.baseAction.isReady():!!c.actionProps.actionType},this.runOrDefer=function(e){return c.isReady()?e():c.deferredCallbacks.push(e)},this.runAllDeferred=function(){for(;c.deferredCallbacks.length;)c.deferredCallbacks.shift()()},this.getActionType=function(){return i.invariant(!!c.actionProps.actionType,"Action type must be defined before accessing it, make sure you are in @behavior instance and not accessing it before initialization"),c.actionProps.actionType},this.getBehavior=function(e){return i.invariant(!!c.behavior,"Trying to get behavior before binding, make sure you are in @behavior instance"),e||c.defaultAffectedBehavior||c.behavior},this.action=function(){for(var e=[],t=0;t<arguments.length;t++)e[t]=arguments[t];var n=c,r=n.actionProps,i=r.payloadCreator,o=r.metaCreator,s=n.type,u=function(e,t){return a.createAction(s(),i,e)(t)},d=function(e){return a.createAction(s(),i)(e)},f=e.length>0?e[0]:void 0;return o?u(o,f):d(f)},this.type=function(){return o.pathAction(c.behavior.path,c.getActionType())},this.finalize=function(e,t){c.behavior=e,c.actionProps=n.__assign(n.__assign({},c.actionProps),t),c.runAllDeferred(),c.baseAction=void 0,c.subscribedActions.splice(0).forEach((function(e){return e.finalize(c.behavior,c.actionProps)}))},this.getInitFn=function(e){return function(t,n){c.baseAction||c.finalize(t,{actionType:e||n})}},this.rawHandle=function(e,t,n,r){return c.runOrDefer((function(){var e=c.getBehavior(r);u.addHandleAction(c.getActionType(),t.bind(e),"throw"===n,c.behavior,e)})),e},this.rawWatch=function(e,t,n){return c.runOrDefer((function(){var e=c.getBehavior(n);d.addActionWatcher(c.getActionType(),t,c.behavior,e)})),e},this.createAction=function(e){var t=function(e){return i.invariant(c.getBehavior().dispatch,"called before store.dispatch is accessible"),c.getBehavior().dispatch(c.action(e)),t};return t.dispatch=t,t},this.useIn=function(n){i.invariant(!!n,"Behavior to be used in must be defined");var r=new e(c);return r.defaultAffectedBehavior=n,c.isReady()?(r.behavior=c.behavior,r.actionProps=c.actionProps):c.subscribedActions.push(r),t.RondoActionFactory.create(r)},this.takeFn=function(e,t,n){c.runOrDefer((function(){var r=c.getBehavior(n);f.addSagaHandler(e,t,[{actionType:c.getActionType(),behavior:c.behavior}],r)}))},this.takeLatest=function(e,t,n){return c.takeFn(t,l,n),e},this.takeLeading=function(e,t,n){return c.takeFn(t,p,n),e},this.takeEvery=function(e,t,n){return c.takeFn(t,v,n),e},r instanceof e?this.baseAction=r:this.actionProps=r}return e.prototype.reduce=function(e,t,r,a){return this.rawHandle(e,(function(e,r){return n.__assign(n.__assign({},e),t(e,r.payload,!!r.error,r.meta))}),r,a)},e})();t.RondoActionCreator=b,t.RondoActionFactory={create:function(e){var t,n;if(e instanceof b)t=e;else{var a=e.metaCreator,i=e.payloadCreator,o=void 0===i?r.identity:i;n=e.actionType,t=new b({payloadCreator:o,metaCreator:a})}var u=t.createAction(n);return u.type=t.type,u.action=t.action,u.init=r.once(t.getInitFn(n)),u[c.ENTRY_FIELD_TYPE]=s.ACTION_FIELD_TYPE,u.watch=function(e,n){return t.rawWatch(u,(function(t,n,r){return e(r(),t.payload)}),n)},u.rawWatch=function(e,n){return t.rawWatch(u,e,n)},u.rawHandle=function(e,n){return t.rawHandle(u,e,"next",n)},u.handle=function(e,n){return t.reduce(u,e,"next",n)},u.rawHandleError=function(e,n){return t.rawHandle(u,e,"throw",n)},u.handleError=function(e,n){return t.reduce(u,e,"throw",n)},u.takeLatest=function(e,n){return t.takeLatest(u,e,n)},u.takeLeading=function(e,n){return t.takeLeading(u,e,n)},u.takeEvery=function(e,n){return t.takeEvery(u,e,n)},u.useIn=t.useIn,u}}}));
//# sourceMappingURL=action_creator.min.js-vflyBW9iO.map
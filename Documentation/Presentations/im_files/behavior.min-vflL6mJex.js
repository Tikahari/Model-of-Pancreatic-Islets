define(["require","exports","tslib","redux-actions","external/lodash","redux-saga","rondo/v1/behavior/types","rondo/v1/behavior/internal_actions","rondo/v1/action_listener_middleware","rondo/v1/metadata_redux","rondo/v1/metadata_action_listener","rondo/v1/slice_actions","rondo/v1/slice_selectors","rondo/v1/behavior/compose/path","rondo/v1/performance","rondo/v1/metadata","rondo/v1/invariant","rondo/v1/selectors","rondo/v1/behavior/compose/compose_behavior","rondo/v1/actions/types","rondo/v1/behavior/handle","rondo/v1/behavior/initial_state","rondo/v1/behavior/action_watcher","rondo/v1/behavior/subscribers","rondo/v1/behavior/utils","rondo/v1/saga/saga_creator"],(function(t,e,i,r,o,n,s,a,c,h,p,d,l,u,f,v,_,y,g,E,m,b,S,A,O,B){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),o=i.__importStar(o),n=i.__importDefault(n);function T(t,r,o){var n,s=O.isBehaviorClass(t)?t:e.behavior(t),a=r||{slicePath:void 0,context:void 0},c=a.slicePath,h=a.context,p=i.__rest(a,["slicePath","context"]);return c||h?(_.invariant(0===Object.keys(p).length,"createBehavior options cannot include fields other than slicePath and context"),n=new s({slicePath:c,context:h})):n=Object.keys(p).length>0?new s(o,p):new s(void 0),n}e.behavior=function(t){return(function(e){function O(){for(var r=[],n=0;n<arguments.length;n++)r[n]=arguments[n];var a=e.call(this,r.length>1?r[1]:void 0)||this;a.__type__=s.BEHAVIOR_FIELD_TYPE,a.sagas=[],a._path=[],a._registerCount=0,a._createErrorHandles=function(){a.actionHandlers=a.actionHandlers||[],h.getHandleActionErrorEntries(t.prototype).forEach((function(t){t.element=t.element.bind(a),t.value.actions.forEach((function(e){return a.actionHandlers.push(new m.HandleAction(t.element,e.actionType,!0,e.useSlice,a,a))}))}))},a._createHandles=function(){a.actionHandlers=a.actionHandlers||[],h.getHandleActionEntries(t.prototype).forEach((function(t){t.element=t.element.bind(a),t.value.actions.forEach((function(e){return a.actionHandlers.push(new m.HandleAction(t.element,e.actionType,!1,e.useSlice,a,a))}))}))},a._createActionWatchers=function(){a.actionWatchers=a.actionWatchers||[],p.getWatchActionEntries(t.prototype).forEach((function(t){t.value.actions.forEach((function(e){return a.actionWatchers.push(new S.ActionWatcher(t.element,e.actionType,e.useSlice,a,a))}))}))},a.getState=function(){return _.invariant(!!a._getState,"Trying to access "+a.id+" state before store is set"),a.path.length>0?o.get(a._getState(),a.path):a._getState()},a.getFullState=function(){return _.invariant(!!a._getState,"Trying to access "+a.id+" state before store is set"),a._getState()},a.collectReducers=function(t){var e;if(t!==a){if(t.isRegistered)return;(e=a.actionHandlers).push.apply(e,i.__spread(t.actionHandlers||[]))}t.composedBehaviors&&t.composedBehaviors.forEach(a.collectReducers)},a.collectInitialStates=function(t){var e;if(t!==a){if(t.isRegistered)return;(e=a.initialStates).push.apply(e,i.__spread(t.initialStates||[]))}t.composedBehaviors&&t.composedBehaviors.forEach(a.collectInitialStates)},a.collectAction=function(t,e){return void 0===e&&(e={}),v.entriesOfTypeField(a,E.ACTION_FIELD_TYPE).forEach((function(t){var i=t.key,r=t.field;return o.set(e,a.path.concat(i),r)})),t.composedBehaviors&&t.composedBehaviors.forEach((function(t){return t.collectAction(t,e)})),e},a.collectActionWatcher=function(t){var e;if(t!==a){if(t.isRegistered)return;(e=a.actionWatchers).push.apply(e,i.__spread(t.actionWatchers||[]))}t.composedBehaviors&&t.composedBehaviors.forEach(a.collectActionWatcher)},a.collectSaga=function(t){var e,r;if(t!==a){if(t.isRegistered)return;(e=a.sagas).push.apply(e,i.__spread(t.sagas||[]))}(r=a.sagas).push.apply(r,i.__spread((t.sagaHandlers||[]).map((function(t){return t.create()})))),t.composedBehaviors&&t.composedBehaviors.forEach(a.collectSaga)};var c=r.length>=1&&s.isBehaviorOptions(r[0])?r[0]:void 0;return c&&(c.context&&(a.context=c.context),"string"==typeof c.slicePath&&(a.slice=c.slicePath)),a.bindMethodsToObject(),a.id=a._generateUniqueId(),a.sagaTasks=[],a.init(),c&&Array.isArray(c.slicePath)&&(a.path=c.slicePath),a}return i.__extends(O,e),O.prototype.ctrKeys=function(){return Object.keys(t.prototype).concat(Object.keys(this))},O.prototype.extendBehavior=function(t){var e=this;t.slice||(v.entriesOfTypeField(t,E.ACTION_FIELD_TYPE).forEach((function(i){var r=i.key;i.field;e.hasOwnProperty(r)||Object.defineProperty(e,r,Object.getOwnPropertyDescriptor(t,r))})),v.entriesOfTypeField(t,y.SELECTOR_FIELD_TYPE).forEach((function(i){var r=i.key;i.field;e.hasOwnProperty(r)||Object.defineProperty(e,r,Object.getOwnPropertyDescriptor(t,r))})),v.entriesOfTypeField(t,s.BEHAVIOR_FIELD_TYPE).forEach((function(i){var r=i.key;Object.defineProperty(e,r,Object.getOwnPropertyDescriptor(t,r)),e._ignoreCompose=(e._ignoreCompose||[]).concat(r)})))},O.prototype.init=function(){var e=this;v.entriesOfTypeField(this,s.BEHAVIOR_FIELD_TYPE,this.ctrKeys()).forEach((function(t){var i=t.key,r=t.field;(!e._ignoreCompose||e._ignoreCompose.indexOf(i)<0)&&g.composeBehavior(e,r,r.slice||i)})),this.actions=h.createActions(t.prototype,this,this.actions),this._createHandles(),this._createErrorHandles(),this._createActionWatchers(),this.initialStates=this.initialStates||[],this.initialState&&this.initialStates.push(new b.InitialState(this.initialState,this)),this.sagas=[],h.createActionCreators(t.prototype,this.path,this),v.entriesOfTypeField(this,E.ACTION_FIELD_TYPE).forEach((function(t){var i=t.key;return t.field.init(e,v.camelCaseToUnderscorePattern(i))})),this.selectors=this.selectors||{},v.entriesOfTypeField(this,y.SELECTOR_FIELD_TYPE).forEach((function(t){var i=t.key,r=t.field;r.init(e),e.selectors[i]=r})),v.entriesOfTypeField(this,B.SAGA_FIELD_TYPE).forEach((function(t){var i=t.key,r=t.field.bind(e);e[i]=r,e.sagas.push(r)})),this.pendingComposedBehaviors&&this.pendingComposedBehaviors.length>0&&g.composeBehaviors(this.pendingComposedBehaviors.splice(0))(this),this._initBehaviorReducer()},O.prototype.bindMethodsToObject=function(){var e,r;try{for(var n=i.__values(Object.getOwnPropertyNames(t.prototype)),s=n.next();!s.done;s=n.next()){var a=s.value,c=this[a];o.isFunction(c)&&"constructor"!==a&&(this[a]=c.bind(this))}}catch(t){e={error:t}}finally{try{s&&!s.done&&(r=n.return)&&r.call(n)}finally{if(e)throw e.error}}},O.prototype.addBehavior=function(t){(this.pendingComposedBehaviors=this.pendingComposedBehaviors||[]).push(t),this.extendBehavior(t)},O.prototype.addUnsubscribers=function(){for(var t,e=[],r=0;r<arguments.length;r++)e[r]=arguments[r];(t=this.unsubscribers=this.unsubscribers||[]).push.apply(t,i.__spread(e))},Object.defineProperty(O.prototype,"_displayName",{get:function(){return this.constructor.displayName},enumerable:!0,configurable:!0}),O.prototype._generateUniqueId=function(){return"BEHAVIOR-"+(this._displayName?this._displayName+"-":"")+(this.slice?this.slice+"-":"")+Math.random().toString(36).substr(2,9)},O.prototype._initBehaviorReducer=function(){var t=this;this._attachReducer(a.actionInitBehavior(this.id),(function(e,i){var r=b.mergeInitialState(t.initialStates,t.path);return r?o.assignIn({},r,e):e}))},O.prototype._attachReducer=function(t,e){this.actionHandlers=this.actionHandlers||[],this.actionHandlers.push(new m.HandleAction(e,t,!1,!1,this,this))},Object.defineProperty(O.prototype,"path",{get:function(){return this._path?this._path.concat(this.slice||[]):[]},set:function(e){this._path=e,this.composedBehaviors&&u.setComposePath(this.composedBehaviors,this.path),h.createActionCreators(t.prototype,this.path,this)},enumerable:!0,configurable:!0}),O.prototype.pathState=function(t){return this.path.length>0?o.get(t,this.path):t},Object.defineProperty(O.prototype,"context",{get:function(){return this._context},set:function(t){this._context=t,this.composedBehaviors&&this.composedBehaviors.forEach((function(e){return e.context=t}))},enumerable:!0,configurable:!0}),O.prototype.createActions=function(){var t=d.createActions(this.actions,this.path);return this.collectAction(this,t),t},O.prototype.createWatchers=function(t){var e=t.get(s.ACTION_LISTENERS_MIDDLEWARE);e||(e=c.ActionListenerMiddleware(),t.register({name:s.ACTION_LISTENERS_MIDDLEWARE,middleware:e,order:0})),this.collectActionWatcher(this),this.addUnsubscribers.apply(this,i.__spread(this.actionWatchers.map((function(t){return t.create(e)}))))},O.prototype.middlewares=function(t){this.isRegistered||(this.createWatchers(t),this.createSagaMiddleware(t))},O.prototype.createSagaMiddleware=function(t){var e=t.get(s.SAGA_MIDDLEWARE);e||(e=n.default(),t.register({name:s.SAGA_MIDDLEWARE,middleware:e,order:0}))},O.prototype.postStoreCreation=function(e,i){var r=this;if(this.store=e,this.dispatch=e.dispatch,this._getState=e.getState,v.entriesOfTypeField(this,A.STATE_SUBSCRIBER_FIELD_TYPE).forEach((function(t){t.key;var i=t.field;i.behavior=r,i.store=e})),this.composedBehaviors&&this.composedBehaviors.forEach((function(t){t.postStoreCreation(e)})),i){var o=i.get(s.SAGA_MIDDLEWARE);o&&!this.isRegistered&&(this.collectSaga(this),this.sagas.forEach((function(t){return r.sagaTasks.push(o.run(t))})))}if(t.prototype.hasOwnProperty("ready")){var n=e.getState();this.ready(this.pathState(n),n)}},O.prototype.createReducer=function(){this.collectInitialStates(this),this.collectReducers(this);var t=b.mergeInitialState(this.initialStates,this.path);if(0===this.actionHandlers.length)return function(e){return void 0===e&&(e=t),e};var e=m.mergeHandles(this.actionHandlers);return r.handleActions(e,t)},O.prototype.createSelectors=function(){var t=this;return l.select(this.selectors,(function(e){return t.slice?e[t.slice]:e}))},Object.defineProperty(O.prototype,"isRegistered",{get:function(){return this._registerCount>0},enumerable:!0,configurable:!0}),O.prototype.register=function(){return this._registerCount++,(this.composedBehaviors||[]).forEach((function(t){return t.register()})),this._registerCount},O.prototype.unregister=function(t){return void 0===t&&(t=!1),this._registerCount--,(this.composedBehaviors||[]).forEach((function(t){return t.unregister(!0)})),this.isRegistered||(this.unsubscribers&&this.unsubscribers.length>0&&this.unsubscribers.splice(0).forEach((function(t){return t()})),t&&(this.actionWatchers=[],this.sagaHandlers=[],this.sagas=[]),this.sagaTasks.forEach((function(t){return t.cancel()})),this.sagaTasks=[],this.dispatch=void 0,this.store=void 0,this._getState=void 0),this._registerCount},O.__type__=s.BEHAVIOR_CLASS_FIELD_TYPE,O.displayName=(function(t){return t.hasOwnProperty("displayName")})(t)?t.displayName:(function(t){return t.hasOwnProperty("name")})(t)?t.name:"Behavior-"+Math.random().toString(36).substr(2,9),i.__decorate([f.markAroundDecorator("init")],O.prototype,"init",null),O})(t)},e.createBehavior=T,e.extendBehavior=function(t,e){O.isBehavior(e)||(e=T(e)),t.addBehavior(e)}}));
//# sourceMappingURL=behavior.min.js-vflW7TKBw.map
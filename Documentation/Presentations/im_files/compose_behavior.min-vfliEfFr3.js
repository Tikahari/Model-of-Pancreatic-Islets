define(["require","exports","tslib","rondo/v1/behavior/behavior_slice","rondo/v1/behavior/create","rondo/v1/behavior/utils","rondo/v1/behavior/elements","rondo/v1/slice_actions","rondo/v1/slice_selectors"],(function(e,o,s,i,r,c,t,a,n){"use strict";Object.defineProperty(o,"__esModule",{value:!0}),o.composeBehaviors=function(e){return function(o){o.composedBehaviors=s.__spread(o.composedBehaviors||[],r.createBehaviors(e,o.path||[])),o.actions=a.combineSliceActions(s.__spread([o.actions],t.sliceNoSliceElements(o.composedBehaviors,["actions"]))),o.selectors=n.combineSliceSelectors(s.__spread([o.selectors],t.elements(o.composedBehaviors,["selectors"]))),o.composedBehaviors.forEach((function(e){e.composerBehavior=o,e.context=o.context}))}},o.composeBehavior=function(e,o,s){s&&(c.isBehavior(o)?o.slice||(o.slice=s):o=i.withSlice(s)(o));var t=r.createBehaviors([o],e.path||[]);return e.addBehavior(t[0]),t[0]}}));
//# sourceMappingURL=compose_behavior.min.js-vflCVZrwt.map